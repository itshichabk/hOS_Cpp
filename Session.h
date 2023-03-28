#pragma once
#include "UserManager.h"
#include "Login.h"
#include "MainMenu.h"

class Session
{
private:
	User* _crntUser;
	MainMenu* _mainMenu;

public:
	User* getCrntUser() const;
	void startSession(User* user);
	void logoff();

	void showMainMenu();
};

