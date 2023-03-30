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
