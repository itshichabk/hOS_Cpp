/*
	hOS Program Manager
	===================

	The program manager loads available programs into a vector of Programs
	which will then be sent to the Main Menu to be displayed for the user.

	It's also in charge of running and closing program instances.
*/

#pragma once
#include "Program.h"

class ProgramMgr
{
private:
	std::vector<Program*> _programs;
	Program* _instance = NULL;

public:
	ProgramMgr();
	const std::vector<Program*> getPrograms() const;
	Program* getProgram(int i) const;

	void runProgram(int index);
	void closeProgram();
};

