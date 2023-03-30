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

	void showMsgBox(MsgBox::type type, std::string message, int sleep = 0);

	void showMessage(int code);
	void printMessage(std::string message);

	bool isUserNew();
};

