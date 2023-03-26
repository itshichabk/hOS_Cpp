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

