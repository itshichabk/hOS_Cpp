/*
*	hOS Message Box
*	===============
* 
*	A custom WINDOW that displays a message in different types (Information, question, warning, error).
*	
*	The number of seconds the message box is displayed can also be set.
*	If none is set, the message box will wait for the user's input to be closed.
*/

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

void showMsgBox(MsgBox::type type, std::string message, int sleep = 0);