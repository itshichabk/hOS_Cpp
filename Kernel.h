#pragma once
#include <curses.h>
#include "UserManager.h"
#include "Login.h"
#include "Session.h"

class Kernel
{
private:
	UserManager _userMgr;
	Login _login;
	Session _session;
	
	bool exception = false;
	bool exit = false;

public:
	Kernel();
	~Kernel();

	void runtime();
	void crash();
};

void initOS();