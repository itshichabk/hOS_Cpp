#pragma once
#include "UserManager.h"
#include "Login.h"
#include "MainMenu.h"
#include "ProgramMgr.h"

class Session
{
private:
	User* _crntUser;
	MainMenu* _mainMenu;
	ProgramMgr _programMgr;

public:
	User* getCrntUser() const;
	MainMenu* getMainMenu();

	void startSession(User* user);
	void logoff();

	void showMainMenu();

};