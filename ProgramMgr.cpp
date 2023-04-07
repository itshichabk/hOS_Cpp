#include <typeinfo>
#include "ProgramMgr.h"
#include "OSVersion.h"
#include "HelloWorld.h"

ProgramMgr::ProgramMgr()
{
	_programs.push_back(new OSVersion);
	_programs.push_back(new HelloWorld);
	_programs.push_back(new OSVersion);

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
	// TODO: check admin/guest rights before launching program

	std::string type = typeid(*_programs[index]).name();
	type.erase(0, 6);

	if (type == "HelloWorld")
		_instance = new HelloWorld();

	else if (type == "OSVersion")
		_instance = new OSVersion();

	if(_instance != NULL)
		_instance->run();
}

void ProgramMgr::closeProgram()
{
	delete _instance;
	_instance = NULL;
}