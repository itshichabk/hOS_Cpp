#include "Window.h"

Window::Window(int w, int h, bool isCentered, std::string title, bool shadow, int x, int y)
{
	_w = w;
	_h = h;
	_title = title;
	_isCentered = isCentered;
	_shadow = shadow;
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

	//if (_shadow)
	//{
	//	_shadowWin = newwin(h, w, y + 1, x + 1);
	//}
}

Window::Window(const Window& win)
{
	_w = win._w;
	_h = win._h;
	_title = win._title;
	_isCentered = win._isCentered;
	_shadow = win._shadow;
	_x = win._x;
	_y = win._y;

	int x = win._x;
	int y = win._y;

	if (win._isCentered)
	{
		int row, col;
		getmaxyx(stdscr, row, col);

		y = (row - _h) / 2;
		x = (col - _w) / 2;
	}

	_win = newwin(win._h, win._w, y, x);
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
	wclear(_win);
	wrefresh(_win);
	delwin(_win);
	//delwin(_shadowWin);
	_win = NULL;
	//_shadowWin = NULL;
}

WINDOW* Window::getWIN()
{
	return _win;
}

//WINDOW* Window::getShadowWIN()
//{
//	return _shadowWin;
//}

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


