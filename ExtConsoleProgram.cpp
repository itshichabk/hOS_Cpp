#include "ExtConsoleProgram.h"

ExtConsoleProgram::ExtConsoleProgram(std::string exePath, std::string name, std::string fullName, bool guestAccess, bool requiresAdmin)
	: Program(name, fullName, Version(0, 0), 1, 1, requiresAdmin, guestAccess)
{
	_exePath = exePath;
}

ExtConsoleProgram::~ExtConsoleProgram()
{
	system("cls");
}

void ExtConsoleProgram::run()
{
	def_prog_mode();
	endwin();
	system(_exePath.c_str());
	system("cls");
	refresh();
}