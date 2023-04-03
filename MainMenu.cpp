#include "MainMenu.h"
#include "Session.h"

MainMenu::MainMenu(Session* _crntSession, ProgramMgr& progMgr) : _win(45, 10, true, "Main menu")
{
	keypad(_win.getWIN(), true);

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
				progMgr.runProgram(highlight);
				getch();
				progMgr.closeProgram();
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
