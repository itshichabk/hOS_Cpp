#include "MainMenu.h"
#include "Session.h"

MainMenu::MainMenu(Session* crntSession, ProgramMgr& progMgr) : _win(45, 14, true, "Main menu")
{
	keypad(_win.getWIN(), true);

	_crntSession = crntSession;
	int choice;
	int highlight = 0;

	do
	{
		// List all programs from Program Manager
		for (int i = 0; i < progMgr.getPrograms().size(); i++)
		{
			if(i == highlight)
				wattron(getWin().getWIN(), A_REVERSE);

			mvwprintw(getWin().getWIN(),
				getWin().getHeight() / 2 + i - 1,
				(getWin().getWidth() - progMgr.getProgram(i)->getFullName().length()) / 2,
				progMgr.getProgram(i)->getFullName().c_str()
			);

			wattroff(getWin().getWIN(), A_REVERSE);
		}


		// Logoff option
		if (highlight == progMgr.getPrograms().size())
			wattron(getWin().getWIN(), A_REVERSE);

		std::string logoffOption = "Logoff " + _crntSession->getCrntUser()->getName() + "...";

		mvwprintw(getWin().getWIN(),
			getWin().getHeight() / 2 + progMgr.getPrograms().size(),
			(getWin().getWidth() - logoffOption.length()) / 2,
			logoffOption.c_str()
		);

		wattroff(getWin().getWIN(), A_REVERSE);

		// Render everything
		getWin().drawWindow();
		getWin().refreshBox();
		refresh();

		noecho();
		choice = wgetch(getWin().getWIN());

		switch (choice)
		{
		case KEY_UP:
			if (highlight > 0)
				highlight--;
			break;

		case KEY_DOWN:
			if (highlight < progMgr.getPrograms().size())
				highlight++;
			break;

		case 10:	// ENTER key
			if (highlight == progMgr.getPrograms().size())
			{
				_crntSession->logoff();
				delete this;
			}
			else
			{
				/*
					Only run program if:
					1) User is an administrator (admin can run any program)
					2) Guest access is enabled (anyone can use the program)
					3) Guest access is disabled, user is a regular account, and program doesn't require admin
				*/

				if ((_crntSession->getCrntUser()->getType() == "Administrator")
					|| (progMgr.getProgram(highlight)->guestAccess())
					|| (!(progMgr.getProgram(highlight)->guestAccess()) && !(progMgr.getProgram(highlight)->requiresAdmin()) && _crntSession->getCrntUser()->getType() == "Regular")
					)
				{
					progMgr.runProgram(highlight);
					progMgr.closeProgram();
				}

				break;
			}
		}

	} while (choice != 10 || highlight != progMgr.getPrograms().size());

	echo();
}

MainMenu::~MainMenu()
{
}

Window& MainMenu::getWin()
{
	return _win;
}
