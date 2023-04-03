#include "HelloWorld.h"

HelloWorld::HelloWorld() : Program("helloWorld", "Hello World!", Version(0,1), 20, 5)
{

}

void HelloWorld::run()
{
	_win.drawWindow();
}
