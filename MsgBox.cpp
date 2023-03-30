#include <Windows.h>
#include "MsgBox.h"

MsgBox::MsgBox(MsgBox::type type, std::string message, int sleep)
	: _win(message.length() + 9, 5, true)
{
	curs_set(0);
	std::string icon;
	std::string fullMessage;

	switch (type)
	{
	case info:
		wattron(_win.getWIN(), COLOR_PAIR(1));
		icon = "(i)";
		break;

	case question:
		wattron(_win.getWIN(), COLOR_PAIR(1));
		icon = "(?)";
		break;

	case warning:
		wattron(_win.getWIN(), COLOR_PAIR(2));
		icon = "/!\\";
		break;

	case error:
		wattron(_win.getWIN(), COLOR_PAIR(3));
		icon = "(x)";
		break;
	}

	fullMessage = icon + "  " + message;

	box(_win.getWIN(), 0, 0);
	mvwprintw(_win.getWIN(), 2, 2, fullMessage.c_str());
	wrefresh(_win.getWIN());
	noecho();
	if (sleep == 0)
	{
		getch();
	}
	else
	{
		Sleep(sleep*1000);
	}

}

MsgBox::~MsgBox()
{
	_message = "";

	echo();
	//curs_set(1);

	wclear(_win.getWIN());
	wrefresh(_win.getWIN());

}
