#include "OSVersion.h"

OSVersion::OSVersion() : Program("ver", "About hOS", Version(0,1), 50, 7)
{

}

void OSVersion::run()
{
	mvwprintw(_win.getWIN(), 1, 1, "placeholder version");
	_win.drawWindow();
}