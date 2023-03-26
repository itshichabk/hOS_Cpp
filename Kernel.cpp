#include "Kernel.h"

Kernel::Kernel()
{
}

Kernel::~Kernel()
{
    endwin();
}

void Kernel::runtime()
{
    _session.startSession( _login.loginPrompt(_userMgr) );

    clear();

    _session.showMainMenu();

}

void initOS()
{
    initscr();
    curs_set(0);
    resize_term(30, 100);
    refresh();

    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    else
    {
        start_color();
        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);
        init_pair(3, COLOR_RED, COLOR_BLACK);
    }
}
