#pragma once
#include "Window.h"

class MessageBox
{
private:
	std::string _message;
	Window _win;

public:
	enum type { info, question, warning, error };

	MessageBox(MessageBox::type type, std::string message);
	~MessageBox();

	void show();
	void close();
};

