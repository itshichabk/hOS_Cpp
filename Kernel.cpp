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
    if (userMgr.doesUsersExist())
    {

    }
    login.loginPrompt(userMgr);
    system("pause>0");
}

void initOS()
{
    initscr();
    curs_set(0);
    resize_term(30, 100);
    refresh();
}
