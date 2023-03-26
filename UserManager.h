#pragma once
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

