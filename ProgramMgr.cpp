#include <typeinfo>
#include "ProgramMgr.h"
#include "OSVersion.h"
#include "HelloWorld.h"

ProgramMgr::ProgramMgr()
{
	_programs.push_back(new OSVersion);
	_programs.push_back(new HelloWorld);
}

const std::vector<Program*> ProgramMgr::getPrograms() const
{
	return _programs;
}

Program* ProgramMgr::getProgram(int i) const
{
	return _programs[i];
}

void ProgramMgr::runProgram(const int index)
{
	_instance = new Program(_programs[index]->getInstance());
	_instance->getWin().drawWindow();
}

void ProgramMgr::closeProgram()
{
	//_instance->getWin().~Window();
	delete _instance;
	_instance = NULL;
}