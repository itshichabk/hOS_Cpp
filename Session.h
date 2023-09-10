/*
*	hOS Session
*	===========
*	
*	A session is started once a user logs in, and has its own list of 
*	personal settings (not yet) and programs depending on the user and its type.
* 
*	It also prevents a user from launching a program it's not allowed to
*	depending on its type (Regular or Guest), 
	and gives full privileges to a user with type Administrator.
*/

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
	ProgramMgr _programMgr;
	MainMenu* _mainMenu;

public:
	Session(User* user);
	User* getCrntUser() const;
	MainMenu* getMainMenu();

	void startSession(User* user, AudioEngine* _audio);
	void runtime();
	void logoff();

	void showMainMenu();

};