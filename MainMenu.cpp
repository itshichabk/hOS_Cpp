#include "MainMenu.h"

MainMenu::MainMenu() : _win(45, 30, true, "Main menu")
{
	
}

Window& MainMenu::getWin()
{
	return _win;
}
