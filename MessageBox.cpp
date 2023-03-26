#include "MessageBox.h"

MessageBox::MessageBox(MessageBox::type type, std::string message)
	: _win(message.length() + 3 + message.length() % 2, 5, true)
{
	curs_set(0);

	switch (type)
	{
	case info:
		wattron(_win.getWIN(), COLOR_PAIR(1));
		break;
	case question:
		wattron(_win.getWIN(), COLOR_PAIR(1));
		break;
	case warning:
		wattron(_win.getWIN(), COLOR_PAIR(2));
		break;
	case error:
		wattron(_win.getWIN(), COLOR_PAIR(3));
		break;
	}

	box(_win.getWIN(), 0, 0);
	mvwprintw(_win.getWIN(), 2, 2, message.c_str());
	wrefresh(_win.getWIN());
	noecho();
	getch();

}

MessageBox::~MessageBox()
{
	echo();

	curs_set(1);
	delwin(_win.getWIN());

	_message = "";
}
