#pragma once
#include "Program.h"

class ProgramMgr
{
private:
	std::vector<Program*> _programs;

public:
	ProgramMgr();
	const std::vector<Program*> getPrograms() const;
	Program* getProgram(int i) const;
};

