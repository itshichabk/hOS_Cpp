#include "Version.h"

Version::Version(int maj, int min)
{
	_maj = maj;
	_min = min;
}

const std::string Version::getVersion() const
{
	return std::to_string(_maj) + '.' + std::to_string(_min) + " (" + _date + " " + _time + ")";
}
