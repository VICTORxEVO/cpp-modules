#include "phonebook.hpp"
#include <iomanip> // Include for std::setw
#include <string>  // Include for std::string

void phonebook::add(void)
{
    std::string first, last;

    std::cout << "Enter first and last name: ";
    std::cin >> first >> last;
    this->contacts[this->index].WriteFirstName(first);
    this->contacts[this->index].WriteLastName(last);
}

void phonebook::search(void)
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < 8; ++i) // Assuming max 8 contacts
    {
        // Check if contact exists or implement logic to track actual count
        std::string firstName = this->contacts[i].GetFirstName();
        std::string lastName = this->contacts[i].GetLastName();
        std::string nickName = this->contacts[i].GetNickName();

        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 10) + "." : firstName);
        std::cout << "|" << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 10) + "." : lastName);
        std::cout << "|" << std::setw(10) << (nickName.length() > 10 ? nickName.substr(0, 10) + "." : nickName);
        std::cout << "|" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
}