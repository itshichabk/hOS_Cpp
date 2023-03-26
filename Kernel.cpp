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
}
