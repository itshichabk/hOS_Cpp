#include "Session.h"
#include "MsgBox.h"

void Session::startSession(User* user, AudioEngine* audio)
{
}

Session::Session(User* user)
{
	// Set session's current user
	_crntUser = user;

	// Welcome message!
	showMsgBox(MsgBox::info, "Welcome " + getCrntUser()->getName(), 2);

	// Creates a main menu based on the user's account type (permissions)
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

