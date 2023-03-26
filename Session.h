#pragma once
#include "UserManager.h"
#include "Login.h"
#include "MainMenu.h"

class Session
{
private:
	User* _crntUser;
	MainMenu _mainMenu;

public:
	void startSession(User* user);
	void showMainMenu();
	User* getCrntUser() const;
};

