/*
*   hOS User
    ========

    A user in the OS has a name, a password, and a type (admin, regular, or guest) which will determine
    which actions the user's allowed to do in a session.
*/

#pragma once
#include <string>

class User
{
private:
    std::string _name;
    std::string _pwd;
    enum type { admin, regular, guest } _type;

public:
    User(std::string name, std::string pwd, int typeInt);
    std::string getName() const;
    std::string getPwd() const;
    const std::string getType() const;
    const int getTypeInt() const;

};

