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

const std::string User::getType() const
{
    std::string type;

    switch (_type)
    {
    case type::admin:
        type = "Administrator";
        break;
    case type::regular:
        type = "Regular";
        break;
    case type::guest:
        type = "Guest";
        break;
    }

    return type;
}

const int User::getTypeInt() const
{
    return _type;
}
