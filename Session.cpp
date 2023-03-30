#include "Session.h"

void Session::startSession(User* user)
{
	_crntUser = user;
	_mainMenu = new MainMenu();
}

void Session::logoff()
{
	/*
		 Will it be the same main menu for all users ?
		 If so, pointer to a single MainMenu
	*/
	_crntUser = NULL;
	delete _mainMenu;
}

MainMenu* Session::getMainMenu()
{
	return _mainMenu;
}

User* Session::getCrntUser() const
{
	return _crntUser;
}

void Session::showMainMenu()
{
	_mainMenu = new MainMenu();

	for (int i = 0; i < _programMgr.getPrograms().size(); i++)
	{
		mvwprintw(	_mainMenu->getWin().getWIN(), 
					_mainMenu->getWin().getHeight() / 2 + i,
					(_mainMenu->getWin().getWidth() - _programMgr.getProgram(i)->getFullName().length()) / 2,
					_programMgr.getProgram(i)->getFullName().c_str()
		);
	}

	//std::string verPlaceHolder = "hOS v03.25.23";
	//std::string user = "Current user name : " + _crntUser->getName();
	//std::string type = "Current user type : " + _crntUser->getType();

	//mvwprintw(	_mainMenu->getWin().getWIN(),
	//			_mainMenu->getWin().getHeight() / 2 - 1,
	//			(_mainMenu->getWin().getWidth() - verPlaceHolder.length()) / 2,
	//			verPlaceHolder.c_str()
	//);

	//mvwprintw(	_mainMenu->getWin().getWIN(),
	//			_mainMenu->getWin().getHeight() / 2,
	//			(_mainMenu->getWin().getWidth() - user.length()) / 2,
	//			user.c_str()
	//);

	//mvwprintw(	_mainMenu->getWin().getWIN(),
	//			_mainMenu->getWin().getHeight() / 2 + 1,
	//			(_mainMenu->getWin().getWidth() - type.length()) / 2,
	//			type.c_str()
	//);

	_mainMenu->getWin().drawWindow();
	noecho();
	getch();
	echo();
	logoff();
}