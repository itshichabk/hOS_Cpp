#pragma once

//#define MAXIMIZED
#define OSVERSION_MAJ 0
#define OSVERSION_MIN 1

#include <curses.h>
#include <Windows.h>

#include "UserManager.h"
#include "Login.h"
#include "MainMenu.h"
#include "Session.h"
#include "AudioEngine.h"
#include "Version.h"

class Kernel
{
private:
	Version _ver;

	UserManager _userMgr;
	Login _login;
	Session* _session;
	MsgBox* _msgBox;
	
	AudioEngine _audio;

	//int _majVer = 0,
	//	_minVer = 1;

	//std::string _buildDate = __DATE__;
	//std::string _buildTime = __TIME__;
	
	bool exception = false;
	bool exit = false;

public:
	Kernel();
	~Kernel();

	void runtime();
	void crash();

	std::string getVersion();
	//void showMsgBox(MsgBox::type type, std::string message, int sleep = 0);
};

void initOS();