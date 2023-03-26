#pragma once
#include <curses.h>
#include <string>

class Window
{
protected:
	WINDOW* _win;

	int _x, _y,
		_w, _h;

	std::string _title;
	bool _shadow = false;

public:
	Window(int w, int h,
		bool isCentered,
		std::string title = "",
		bool shadow = false,
		int x = 0, int y = 0);
	~Window();

	WINDOW* getWIN();
	const int getWidth() const;
	const int getHeight() const;

	void centerWindow();
	void drawWindow();

	void refreshBox();
};

