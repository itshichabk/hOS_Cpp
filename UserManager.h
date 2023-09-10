#pragma once
/*
*	hOS User Manager
*	================
*
*	Loads users from a file named 'users', that contains a list of 
*	usernames, passwords (security/10) and account types,
*	into a vector of Users. 
*	The user manager is in charge of creating new users 
*	and adding them to the file. 
* 
*	(TODO!) In case the logged user is an Admin, the user manager
*	also allows the user to edit existing users and delete them.
*/

#include <vector>
#include <fstream>

#include "User.h"

class UserManager
{
private:
	std::vector<User> users;
	std::ifstream usersFileIn;
	std::ofstream usersFileOut;

public:
	UserManager();
	~UserManager();

	std::vector<User>& getUsers();

	const User& getUser(int i) const;
	const User& operator[](int i) const;

	bool doesUsersExist();

	void importUsers();
	void createUser(std::string name, std::string pwd, int type);
	void addUser(User& user);
	void editUser();
	void deleteUser();

	bool openUsersIn();
	bool openUsersOut();

	//bool usernameExists(std::string username);
};

