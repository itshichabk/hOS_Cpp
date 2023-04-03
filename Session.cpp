#include "Session.h"
#include "MsgBox.h"

void Session::startSession(User* user, AudioEngine* audio)
{
}

Session::Session(User* user)
{
	_crntUser = user;

	//audio->playAudio("logon.wav");
	showMsgBox(MsgBox::info, "Welcome " + getCrntUser()->getName(), 2);

	_mainMenu = new MainMenu(this, _programMgr);

}

void Session::logoff()
{
	_crntUser = NULL;
}

MainMenu* Session::getMainMenu()
{
	return _mainMenu;
}

User* Session::getCrntUser() const
{
	return _crntUser;
}

