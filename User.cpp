#include "User.h"

User::User(std::string name, std::string pwd, int typeInt)
{
    _name = name;
    _pwd = pwd;

    switch (typeInt)
    {
    case 0:
        _type = type::admin;
        break;
    case 1:
        _type = type::regular;
        break;
    case 2:
        _type = type::guest;
        break;
    default:
        // invalid type
        delete this;
        break;
    }
}

std::string User::getName() const
{
    return _name;
}

std::string User::getPwd() const
{
    return _pwd;
}
