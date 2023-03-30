#include "Program.h"

Program::Program(std::string sysName, std::string fullName, Version ver, int w, int h, bool requiresAdmin, bool guestAccess)
	: _win(w, h, true, fullName), _ver(ver)
{
	_sysName = sysName;
	_fullName = fullName;
	_requiresAdmin = requiresAdmin;
	_guestAccess = guestAccess;
}

const std::string Program::getFullName() const
{
	return _fullName;
}
