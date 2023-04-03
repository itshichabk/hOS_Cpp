#pragma once
#include "Window.h"
#include "ProgramMgr.h"

class Session;

class MainMenu
{
private:
	Window _win;

public:
	MainMenu(Session* _crntSession, ProgramMgr& progMgr);
	~MainMenu();
	Window& getWin();

};
