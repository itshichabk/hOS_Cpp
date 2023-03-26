#include "Window.h"

Window::Window(int w, int h, bool isCentered, std::string title, bool shadow, int x, int y)
{
	_w = w;
	_h = h;
	_title = title;
	shadow = _shadow;
	_x = x;
	_y = y;

	if (isCentered)
	{
		int row, col;
		getmaxyx(stdscr, row, col);

		y = (row - _h) / 2;
		x = (col - _w) / 2;
	}

	_win = newwin(h, w, y, x);
	box(_win, 0, 0);
}

Window::~Window()
{
	_x = 0;
	_y = 0;
	_w = 0;
	_h = 0;
	_title = "";
	_shadow = false;
	_win = NULL;
}

WINDOW* Window::getWIN()
{
	return _win;
}

const int Window::getWidth() const
{
	return _w;
}

const int Window::getHeight() const
{
	return _h;
}

void Window::centerWindow()
{
	int row, col;
	getmaxyx(stdscr, row, col);
	
	wmove(_win, (row - _h) / 2, (col - _w) / 2);
}

void Window::drawWindow()
{
	mvwprintw(_win, 0, (_w - _title.length()) / 2, _title.c_str());
	wrefresh(_win);
}

void Window::refreshBox()
{
	box(_win, 0, 0);
	mvwprintw(_win, 0, (_w - _title.length()) / 2, _title.c_str());

	wrefresh(_win);
}


