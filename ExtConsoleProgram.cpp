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

// Special code to run the console program in the same window and seamlessly go back to the OS after finishing
void ExtConsoleProgram::run()
{
	def_prog_mode();
	endwin();
	system(_exePath.c_str());
	system("cls");
	refresh();
}