#include "HelloWorld.h"

HelloWorld::HelloWorld() : Program("helloWorld", "Hello World!", Version(0,1), 20, 5)
{
}

void HelloWorld::run()
{
	mvwprintw(_win.getWIN(), 1, 1, "Hello!!!");
	_win.drawWindow();
}
