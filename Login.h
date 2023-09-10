/*
*	hOS Login Component
*	===================
* 
*	The login process either logs in to an existing account or creates a new one
*	depending on the user's input. (if username exists)
* 
*	Once the login process is done, it returns the connected User
*	so a Session can be initialized with it.
*/

#pragma once
#include <vector>
#include "Window.h"
#include "UserManager.h"
#include "MsgBox.h"

class Login
{
private:
	Window _win;
	MsgBox* _msgBox = NULL;

	int _userIndex = 0;
	std::string _userIn = "";
	std::string _pwdIn = "";

	bool _newUser;

public:
	Login();

	User* loginPrompt(UserManager& userMgr);

	void printWindow();
	std::string scanUser();
	std::string scanPwd();

	bool userExists(std::vector<User>& users);
	bool pwdExists(User& user);

	void showMessage(int code);
	void printMessage(std::string message);

	bool isUserNew();
};

