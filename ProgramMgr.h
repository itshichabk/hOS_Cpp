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

