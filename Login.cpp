#include "Login.h"
#include "MsgBox.h"

Login::Login() : _win(40, 7, true, "Login")
{
}

User* Login::loginPrompt(UserManager &userMgr)
{
	printWindow();
	_win.refreshBox();

	if (!userMgr.doesUsersExist())
	{
		showMsgBox(MsgBox::warning, "No users file, creating new account.");
	}

	scanUser();
	_win.refreshBox();
	
	if (userMgr.doesUsersExist() && userExists(userMgr.getUsers()))
	{
		_newUser = false;
		//showMsgBox(MsgBox::info, "'" + _userIn + "' exists.");

		do
		{
			scanPwd();
			_win.refreshBox();

			if (pwdExists(userMgr.getUsers()[_userIndex]))
			{
				printMessage("Welcome " + userMgr.getUsers()[_userIndex].getName());
				break; 

			}
			else
			{
				showMsgBox(MsgBox::error, "Wrong password. Please try again.", 1);
				showMessage(3);
			}

		} while (1);
	}
	else
	{
		_newUser = true;
		showMsgBox(MsgBox::info, "'" + _userIn + "' doesn't exist. Creating new account.", 2);

		scanPwd();

		userMgr.createUser(_userIn, _pwdIn, 1);
		_userIndex = userMgr.getUsers().size() - 1;
	}

	wclear(_win.getWIN());
	wrefresh(_win.getWIN());
	return &userMgr.getUsers()[_userIndex];
}

void Login::showMsgBox(MsgBox::type type, std::string message, int sleep)
{
	_msgBox = new MsgBox(type, message, sleep);
	delete _msgBox;
}

bool Login::isUserNew()
{
	return _newUser;
}

void Login::printWindow()
{
	_win.drawWindow();
	mvwprintw(_win.getWIN(), 2, 3, "User     : ");
	mvwprintw(_win.getWIN(), 4, 3, "Password : ");
	wrefresh(_win.getWIN());
}

bool Login::userExists(std::vector<User>& users)
{
	int i = 0;

	for (User u : users)
	{
		if (_userIn == u.getName())
		{
			_userIndex = i;
			return true;
		}

		i++;
	}

	return false;
}

bool Login::pwdExists(User& user)
{
	return _pwdIn == user.getPwd();
}

std::string Login::scanUser()
{
	wmove(_win.getWIN(), 2, 14);
	wclrtoeol(_win.getWIN());
	_win.refreshBox();

	curs_set(1);

	char userInChar[24] = "";

	mvwgetnstr(_win.getWIN(), 2, 14, userInChar, 24);

	_userIn = userInChar;
	return _userIn;

}

std::string Login::scanPwd()
{
	wmove(_win.getWIN(), 4, 14);
	wclrtoeol(_win.getWIN());
	_win.refreshBox();

	curs_set(1);

	char pwInChar[24] = "";

	//TODO: fix max length string stack corruption error
	mvwgetnstr(_win.getWIN(), 4, 14, pwInChar, 24);

	_pwdIn = pwInChar;
	return _pwdIn;
}

void Login::printMessage(std::string message)
{
	curs_set(0);

	wmove(_win.getWIN(), 7, 0);
	wclrtoeol(_win.getWIN());

	_win.refreshBox();

	wmove(_win.getWIN(), 7, (_win.getWidth() - message.length()) / 2);
	wprintw(_win.getWIN(), message.c_str());
	wrefresh(_win.getWIN());
}


void Login::showMessage(int code)
{
	
	std::string message;

	switch (code)
	{
	case 0:
		message = "Account found.";
		break;
	case 1:
		message = "New account detected.";
		break;
	case 2:
		message = "Login successful.";
		break;
	case 3:
		message = "Wrong password.";
		break;
	case 4:
		message = "No users file, creating new account.";
		break;
	case 5:
		message = "users file found.";
		break;
	}

	wmove(_win.getWIN(), 6, 0);
	wclrtoeol(_win.getWIN());

	_win.refreshBox();

	wmove(_win.getWIN(), 6, (_win.getWidth() - message.length()) / 2);
	wprintw(_win.getWIN(), message.c_str());
	wrefresh(_win.getWIN());
}