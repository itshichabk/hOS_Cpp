/*
*	hOS Main Menu
*	=============
* 
*	The main menu is a list of programs/options that show up once a user session has started.
*/

#pragma once
#include "Window.h"
#include "ProgramMgr.h"

class Session;

class MainMenu
{
private:
	Session* _crntSession;
	Window _win;

public:
	MainMenu(Session* _crntSession, ProgramMgr& progMgr);
	~MainMenu();
	Window& getWin();

};
