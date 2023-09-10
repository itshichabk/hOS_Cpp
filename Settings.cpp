#include "Settings.h"

Settings::Settings() : Program("settings", "System Settings", Version(0, 1), 50, 15, false, false)
{

}

void Settings::run()
{
	mvwprintw(_win.getWIN(), 1, 1, "Placeholder");
	_win.drawWindow();
	getch();
}


