#pragma once
#include <curses.h>
#include "UserManager.h"
#include "Login.h"

class Kernel
{
private:
	UserManager userMgr;
	Login login;
	bool exception = false;

public:
	Kernel();
	~Kernel();

	void runtime();
	void crash();
};

void initOS();