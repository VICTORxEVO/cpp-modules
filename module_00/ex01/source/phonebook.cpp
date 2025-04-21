#include "phonebook.hpp"
#include <iomanip> // Include for std::setw
#include <string>  // Include for std::string

void phonebook::add(void)
{
    std::string first, last, nname;

    std::cout << "Enter first name" << std::endl;
    std::cin >> first;
    std::cout << "enter " << first << "'s last name" << std::endl;
    std::cin >> last;
    std::cout << "enter " << first << "'s nickname" << std::endl;
    std::cin >> nname;
    this->contacts[this->index].WriteFirstName(first);
    this->contacts[this->index].WriteLastName(last);
    this->contacts[this->index].WriteNickName(nname);
    this->index++;
    if (this->index == 8)
        this->index = 0;
}

void phonebook::search(void)
{
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "|    Index  |First Name | Last Name |  Nickname |" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    for (int i = 0; i < 8; ++i)
    {
        std::string firstName = this->contacts[i].GetFirstName();
        std::string lastName = this->contacts[i].GetLastName();
        std::string nickName = this->contacts[i].GetNickName();

        std::cout << "|" << std::setw(11) << i;
        std::cout << "|" << std::setw(11) << (firstName.length() > 10 ? firstName.substr(0, 10) + "." : firstName);
        std::cout << "|" << std::setw(11) << (lastName.length() > 10 ? lastName.substr(0, 10) + "." : lastName);
        std::cout << "|" << std::setw(11) << (nickName.length() > 10 ? nickName.substr(0, 10) + "." : nickName);
        std::cout << "|" << std::endl;
    }
    std::cout << "-------------------------------------------------" << std::endl;
}