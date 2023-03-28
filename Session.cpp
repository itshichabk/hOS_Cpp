#include "Session.h"

void Session::startSession(User* user)
{
	_crntUser = user;
}

void Session::showMainMenu()
{
	_mainMenu = new MainMenu();

	std::string verPlaceHolder = "hOS v03.25.23";
	std::string user = "Current user name : " + _crntUser->getName();
	std::string type = "Current user type : " + _crntUser->getType();


	mvwprintw(_mainMenu->getWin().getWIN(),
			  _mainMenu->getWin().getHeight() / 2 - 1,
			 (_mainMenu->getWin().getWidth() - verPlaceHolder.length()) / 2,
			   verPlaceHolder.c_str()
	);
	
	mvwprintw( _mainMenu->getWin().getWIN(),
		       _mainMenu->getWin().getHeight() / 2,
		      (_mainMenu->getWin().getWidth() - user.length()) / 2,
		       user.c_str()
	);

	mvwprintw( _mainMenu->getWin().getWIN(),
			   _mainMenu->getWin().getHeight() / 2 + 1,
			  (_mainMenu->getWin().getWidth() - type.length()) / 2,
			   type.c_str()
	);

	_mainMenu->getWin().drawWindow();

	getch();
	logoff();

	//wrefresh(_mainMenu->getWin().getWIN());

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

User* Session::getCrntUser() const
{
	return _crntUser;
}