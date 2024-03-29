/*
	hOS Program
	===========

	The basis of an executable program in the OS.

	Each program has :
	- an internal system name
	- a full name
	- a version number
	- permission types (admin only, non-guests only, public)
*/

#pragma once
#include <vector>
#include "Window.h"
#include "Version.h"

class Program
{
protected:
	Window _win;

	std::string _sysName;
	std::string _fullName;
	Version _ver;

	bool _requiresAdmin;
	bool _guestAccess;

public:
	Program(std::string sysName, std::string fullName, Version ver,
			int w, int h, bool requiresAdmin = false, bool guestAccess = true);

	Program(const Program& p);

	const Program& getInstance();
	bool requiresAdmin() const;
	bool guestAccess() const;

	Window& getWin();

	virtual void run();
	void exitProgram();
	const std::string getFullName() const;
};

