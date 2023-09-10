#include "Kernel.h"

Kernel::Kernel() : _ver(OSVERSION_MAJ, OSVERSION_MIN)
{
    runtime();
}

Kernel::~Kernel()
{
    endwin();
}

void Kernel::runtime()
{
    // TODO: To be reworked
    do
    {
        // Initializes a new session
        _session = new Session(_login.loginPrompt(_userMgr));
        //_session.startSession(_login.loginPrompt(_userMgr), &_audio);
        // TODO: move showMsgBox function to kernel
        //showMsgBox(MsgBox::info, "Welcome " + _session.getCrntUser()->getName(), 2);
        //showMsgBox(MsgBox::info, "hOS " + _ver.getVersion(), 2);
        //_login.showMsgBox(MsgBox::info, "Welcome " + _session.getCrntUser()->getName());
        //_login.showMsgBox(MsgBox::info, getVersion());
        //_session.showMainMenu();
        //_session.logoff();
        _audio.playAudio("logoff.wav");

    } while (1);

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
        init_pair(1, COLOR_CYAN, COLOR_BLACK);      // 'Info' message box color (cyan)
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);    // 'Warning' message box color (yellow)
        init_pair(3, COLOR_RED, COLOR_BLACK);       // 'Error' message box color (red)

    }
}
