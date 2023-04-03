#include "Program.h"

Program::Program(std::string sysName, std::string fullName, Version ver, int w, int h, bool requiresAdmin, bool guestAccess)
	: _win(w, h, true, fullName), _ver(ver)
{
	_sysName = sysName;
	_fullName = fullName;
	_requiresAdmin = requiresAdmin;
	_guestAccess = guestAccess;
}

Program::Program(const Program& p) : _win(p._win), _ver(p._ver)
{
	_sysName = p._sysName;
	_fullName = p._fullName;
	_requiresAdmin = p._requiresAdmin;
	_guestAccess = p._guestAccess;
}

const Program& Program::getInstance()
{
	return *this;
}

Window& Program::getWin()
{
	return _win;
}

void Program::run()
{

}

void Program::exitProgram()
{

}

const std::string Program::getFullName() const
{
	return _fullName;
}
