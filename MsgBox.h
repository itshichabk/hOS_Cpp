#pragma once
#include "Window.h"

class MsgBox
{
private:
	std::string _message;
	Window _win;

public:
	enum type { info, question, warning, error };

	MsgBox(MsgBox::type type, std::string message, int sleep = 0);
	~MsgBox();

	void show();
	void close();
};

