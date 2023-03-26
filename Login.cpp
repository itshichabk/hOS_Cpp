#include "Login.h"
#include "MessageBox.h"

Login::Login() : _win(45, 10, true, "Login")
{
}

User* Login::loginPrompt(UserManager &userMgr)
{
	printWindow();
	if (!userMgr.doesUsersExist())
	{
		showMessageBox(MessageBox::warning, "No users file, creating new account.");
		showMessage(4);
	}
	else
	{
		showMessageBox(MessageBox::info, "users file found.");
		showMessage(5);
	}

	scanUser();
	_win.refreshBox();
	
	if (userMgr.doesUsersExist() && userExists(userMgr.getUsers()))
	{
		_newUser = false;

		showMessage(0);

		do
		{
			scanPwd();
			_win.refreshBox();

			if (pwdExists(userMgr.getUsers()[_userIndex]))
			{
				std::string message = "Welcome " + userMgr.getUsers()[_userIndex].getName();
				printMessage(message);
				break; 

			}
			else
			{
				showMessageBox(MessageBox::error, "Wrong password. Please try again.");
				showMessage(3);
			}

		} while (1);
	}
	else
	{
		_newUser = true;
		showMessage(1);

		scanPwd();

		userMgr.createUser(_userIn, _pwdIn, 1);
		_userIndex = userMgr.getUsers().size() - 1;
	}

	return &userMgr.getUsers()[_userIndex];

}

void Login::showMessageBox(MessageBox::type type, std::string message)
{
	_msgBox = new MessageBox(type, message);
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

	wmove(_win.getWIN(), 7, 0);
	wclrtoeol(_win.getWIN());

	_win.refreshBox();

	wmove(_win.getWIN(), 7, (_win.getWidth() - message.length()) / 2);
	wprintw(_win.getWIN(), message.c_str());
	wrefresh(_win.getWIN());
}