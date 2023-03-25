#include <fstream>
#include <filesystem>
#include "UserManager.h"

UserManager::UserManager()
{
    if(doesUsersExist())
        importUsers();
}

UserManager::~UserManager()
{

}

 std::vector<User>& UserManager::getUsers() 
{
    return users;
}

const User& UserManager::getUser(int i) const
{
    return users[i];
}

const User& UserManager::operator[](int i) const
{
    return users[i];
}

bool UserManager::doesUsersExist()
{
    return std::filesystem::exists("users");
}

void UserManager::importUsers()
{
    std::ifstream usersFile("users");

    if (!usersFile.is_open())
        exit(1);
        //std::cout << "Error while importing users" << std::endl;
    // TODO: Error handler (Kernel)

    else
    {
        while (!usersFile.eof())
        {
            std::string name;
            std::string pwd;
            int type;

            usersFile >> name >> pwd >> type;

            User user(name, pwd, type);

            users.push_back(user);
        }

        //std::cout << "UserManager : users successfully imported" << std::endl;

    }

    usersFile.close();
}

