#pragma once
#include <string>

class Version
{
private:
	int _maj;
	int _min;

	std::string _date = __DATE__;
	std::string _time = __TIME__;

public:
	Version(int maj, int min);
	const std::string getVersion() const;
};

