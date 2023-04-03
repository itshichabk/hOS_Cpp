#pragma once
#include <curses.h>
#include <string>

class Window
{
protected:
	WINDOW* _win;
	//WINDOW* _shadowWin = NULL;

	int _x, _y,
		_w, _h;

	std::string _title;
	bool _isCentered;
	bool _shadow = false;

public:
	Window(int w, int h,
		bool isCentered,
		std::string title = "",
		bool shadow = false,
		int x = 0, int y = 0);

	Window(const Window& win);

	~Window();

	WINDOW* getWIN();
	//WINDOW* getShadowWIN();

	const int getWidth() const;
	const int getHeight() const;

	void centerWindow();
	void drawWindow();

	void refreshBox();
};

