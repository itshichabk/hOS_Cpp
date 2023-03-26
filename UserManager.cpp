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
    if (openUsersIn())
    {
        while (!usersFileIn.eof())
        {
            std::string name;
            std::string pwd;
            int type;

            usersFileIn >> name >> pwd >> type;

            User user(name, pwd, type);

            users.push_back(user);
        }

        //std::cout << "UserManager : users successfully imported" << std::endl;
        usersFileIn.close();
    }

}

void UserManager::createUser(std::string name, std::string pwd, int type)
{
    User user(name, pwd, type);

    users.push_back(user);

    if (openUsersOut())
    {
         usersFileOut  << user.getName() << " " << user.getPwd() << " " << user.getTypeInt() << std::endl;
         usersFileOut.close();
    }


}

void UserManager::addUser(User& user)
{
    users.push_back(user);

    if (openUsersOut())
    {
        usersFileOut << user.getName() << " " << user.getPwd() << " " << user.getTypeInt() << std::endl;
        usersFileOut.close();
    }

}

bool UserManager::openUsersIn()
{
    usersFileIn.open("users");

    if (!usersFileIn.is_open())
    {
        return false;
        exit(1);
    }
    //std::cout << "Error while importing users" << std::endl;
// TODO: Error handler (Kernel)

    return true;
}

bool UserManager::openUsersOut()
{
    usersFileOut.open("users", std::fstream::app);

    if (!usersFileOut.is_open())
    {
        return false;
        exit(1);
    }
    //std::cout << "Error while importing users" << std::endl;
// TODO: Error handler (Kernel)

    return true;
}

