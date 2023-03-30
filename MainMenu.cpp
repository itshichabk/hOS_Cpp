#include "MainMenu.h"

MainMenu::MainMenu() : _win(45, 20, true, "Main menu")
{
	keypad(_win.getWIN(), true);
}

MainMenu::~MainMenu()
{

}

Window& MainMenu::getWin()
{
	return _win;
}

