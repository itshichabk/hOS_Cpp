#include <Windows.h>
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
    do
    {
        _session.startSession(_login.loginPrompt(_userMgr));

        // TODO: move showMsgBox function to kernel
        _audio.playAudio("logon.wav");
        _login.showMsgBox(MsgBox::info, "Welcome " + _session.getCrntUser()->getName());
        //_login.showMsgBox(MsgBox::info, getVersion());

        _session.showMainMenu();
        _audio.playAudio("logoff.wav");

    } while (1);

}

std::string Kernel::getVersion()
{
    return "hOS++ " + std::to_string(_majVer) + '.' + std::to_string(_minVer) + " (" + _buildDate + " " + _buildTime + ")";
}

void initOS()
{
    #ifdef MAXIMIZED
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    initscr();
    #else
    initscr();
    resize_term(30, 100);
    #endif

    curs_set(0);

    //int x, y;
    //getmaxyx(stdscr, y, x);
    //resize_term(y, x);

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
