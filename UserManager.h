#pragma once
#include <vector>
#include "User.h"

class UserManager
{
private:
	std::vector<User> users;

public:
	UserManager();
	~UserManager();

	std::vector<User>& getUsers();

	const User& getUser(int i) const;
	const User& operator[](int i) const;

	bool doesUsersExist();

	void importUsers();
	void createUser();
	void editUser();
	void deleteUser();

	//bool usernameExists(std::string username);
};

