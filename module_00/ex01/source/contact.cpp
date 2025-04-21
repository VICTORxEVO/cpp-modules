#include "phonebook.hpp"

void contact::WriteFirstName(std::string str)
{
    this->info[0] = str;
}

void contact::WriteLastName(std::string str)
{
    this->info[1] = str;
}

void contact::WriteNickName(std::string str)
{
    this->info[2] = str;
}

std::string contact::GetFirstName(void) const
{
    return this->info[0];
}

std::string contact::GetLastName(void) const
{
    return this->info[1];
}

std::string contact::GetNickName(void) const
{
    return this->info[2];
}