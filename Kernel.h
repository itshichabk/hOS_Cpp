/*
*	hOS Kernel
*	==========
*
*	Contains the fundamentals of the OS, such as its version and audio engine.
*	The kernel is in charge of the communication between the user manager and the current session.
*/

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

	//std::string _buildDate = __DATE__;
	//std::string _buildTime = __TIME__;
	
	bool exception = false;
	bool exit = false;

public:
	Kernel();
	~Kernel();

	// The main "loop" of the OS
	void runtime();

	std::string getVersion();
	//void showMsgBox(MsgBox::type type, std::string message, int sleep = 0);
};

// Initializes curses mode and related properties (colors, window size)
void initOS();