#include "phonebook.hpp"

void contacts::WriteFirstName(std::string str)
{
    this->info[0] = str;
}

void contacts::WriteLastName(std::string str)
{
    this->info[1] = str;
}

void contacts::WriteNickName(std::string str)
{
    this->info[2] = str;
}

std::string contacts::GetFirstName(void) const
{
    return this->info[0];
}

std::string contacts::GetLastName(void) const
{
    return this->info[1];
}

std::string contacts::GetNickName(void) const
{
    return this->info[2];
}