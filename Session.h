#pragma once
#include "UserManager.h"
#include "Login.h"
#include "ProgramMgr.h"
#include "MainMenu.h"
#include "AudioEngine.h"

class Session
{
private:
	User* _crntUser;
	MainMenu* _mainMenu;
	ProgramMgr _programMgr;

public:
	Session(User* user);
	User* getCrntUser() const;
	MainMenu* getMainMenu();

	void startSession(User* user, AudioEngine* _audio);
	void runtime();
	void logoff();

	void showMainMenu();

};