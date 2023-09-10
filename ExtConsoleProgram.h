#pragma once
#include "Program.h"

class ExtConsoleProgram : public Program
{
private:
	std::string _exePath;

public:
	ExtConsoleProgram(std::string exePath, std::string name, std::string fullName, bool guestAccess = true, bool requiresAdmin = false);
	~ExtConsoleProgram();
	void run();
};