#include "OSVersion.h"

OSVersion::OSVersion() : Program("ver", "About hOS (no guest)", Version(0,1), 50, 7, false, false)
{

}

void OSVersion::run()
{
	mvwprintw(_win.getWIN(), 1, 1, "placeholder version");
	_win.drawWindow();
}