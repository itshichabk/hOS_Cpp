#include "HelloWorld.h"

HelloWorld::HelloWorld() : Program("helloWorld", "Hello World! (admin)", Version(0,1), 25, 5, true)
{
}

void HelloWorld::run()
{
	mvwprintw(_win.getWIN(), 1, 1, "Hello!!!");
	_win.drawWindow();
	getch();
}
