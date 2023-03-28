#pragma once

#define MAXIMIZED

#include <curses.h>
#include "UserManager.h"
#include "Login.h"
#include "Session.h"
#include "AudioEngine.h"

class Kernel
{
private:
	UserManager _userMgr;
	Login _login;
	Session _session;
	
	AudioEngine _audio;

	int _majVer = 0,
		_minVer = 1;

	std::string _buildDate = __DATE__;
	std::string _buildTime = __TIME__;
	
	bool exception = false;
	bool exit = false;

public:
	Kernel();
	~Kernel();

	void runtime();
	void crash();

	std::string getVersion();
};

void initOS();