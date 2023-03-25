#include "Login.h"

Login::Login() : _win(45, 10, true, "Login")
{
}

void Login::loginPrompt(UserManager &userMgr)
{
	printWindow();

	if (!userMgr.doesUsersExist())
	{
		showMessage(4);
	}
	else
	{
		showMessage(5);
	}

	scanUser();
	
	if (userMgr.doesUsersExist() && userExists(userMgr.getUsers()))
	{
		showMessage(0);
		scanPwd();

		if (pwdExists(userMgr.getUsers()[_userIndex]))
		{
			showMessage(2);
		}
		else
		{
			showMessage(3);
		}
	}
	else
	{
		showMessage(1);
	}
}

void Login::printWindow()
{
	_win.drawWindow();
	mvwprintw(_win.getWin(), 2, 3, "User     : ");
	mvwprintw(_win.getWin(), 4, 3, "Password : ");
	wrefresh(_win.getWin());
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
	curs_set(1);

	char userInChar[24] = "";

	mvwgetnstr(_win.getWin(), 2, 14, userInChar, 24);

	_userIn = userInChar;
	// no
	return _userIn;
	//mvwscanw(_win, 2, 14, "")

}

std::string Login::scanPwd()
{
	char pwInChar[24] = "";

	mvwgetnstr(_win.getWin(), 4, 14, pwInChar, 24);

	_pwdIn = pwInChar;
	// no
	return _pwdIn;
	//mvwscanw(_win, 2, 14, "")
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

	wmove(_win.getWin(), 7, 0);
	wclrtoeol(_win.getWin());

	_win.refreshBox();

	wmove(_win.getWin(), 7, (_win.getWidth() - message.length()) / 2);
	wprintw(_win.getWin(), message.c_str());
	//mvwprintw(_win.getWin(), 7, (_win.getWidth() - message.length()) / 2, message.c_str());
	wrefresh(_win.getWin());
}
