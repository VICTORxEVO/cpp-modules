#include "phonebook.hpp"
#include <iomanip> // Include for std::setw
#include <string>  // Include for std::string

void phonebook::add(void)
{
    std::string first_name;
    std::string str;

    std::cout << "Enter First name" << std::endl;
    std::getline(std::cin, first_name);
    this->contacts[this->index].SetFirstName(first_name);

    std::cout << "Enter " << first_name << "'s Last name" << std::endl;
    std::getline(std::cin, str);
    this->contacts[this->index].SetLastName(str);

    std::cout << "Enter " << first_name << "'s Nick name" << std::endl;
    std::getline(std::cin, str);
    this->contacts[this->index].SetNickName(str);

    std::cout << "Enter " << first_name << "'s phone number" << std::endl;
    std::getline(std::cin, str);
    this->contacts[this->index].SetPhoneNum(str);

    std::cout << "Enter " << first_name << "'s darkest secret" << std::endl;
    std::getline(std::cin, str);
    this->contacts[this->index].SetSecret(str);


    this->index++;
    if (this->index == 8)
        this->index = 0;
}

void phonebook::search(void)
{
    std::string idx;
    int index;
    std::string firstname, lastname, nickname, phonenum, secret;

    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "|    Index  |First Name | Last Name |  Nickname |" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    for (int i = 0; i < 8; ++i)
    {
        firstname = contacts[i].GetFirstName();
        lastname = contacts[i].GetLastName();
        nickname = contacts[i].GetNickName();

        std::cout << "|" << std::setw(11) << i;
        std::cout << "|" << std::setw(11) << (firstname.length() > 10 ? firstname.substr(0, 10) + "." : firstname);
        std::cout << "|" << std::setw(11) << (lastname.length() > 10 ? lastname.substr(0, 10) + "." : lastname);
        std::cout << "|" << std::setw(11) << (nickname.length() > 10 ? nickname.substr(0, 10) + "." : nickname);
        std::cout << "|" << std::endl;
    }

    std::cout << "-------------------------------------------------" << std::endl;

    std::cout << "Enter contact's index" << std::endl;
    std::getline(std::cin, idx);
        for (size_t j = 0; j < idx.length(); ++j)
        {
            if (!isdigit(idx[j]))
            {
                std::cout << "index must be a number !" << std::endl;
                return ;
            }
        }
    index = atoi(idx.c_str());
    
    firstname = contacts[index].GetFirstName();
    lastname = contacts[index].GetLastName();
    nickname = contacts[index].GetNickName();
    phonenum = contacts[index].GetPhoneNum();
    secret = contacts[index].GetSecret();
    
    std::cout  << (firstname.length() > 10 ? firstname.substr(0, 10) + "." : firstname) << std::endl;
    std::cout << (lastname.length() > 10 ? lastname.substr(0, 10) + "." : lastname) << std::endl;
    std::cout << (nickname.length() > 10 ? nickname.substr(0, 10) + "." : nickname) << std::endl;
    std::cout << (phonenum.length() > 10 ? phonenum.substr(0, 10) + "." : phonenum) << std::endl;
    std::cout << (secret.length() > 10 ? secret.substr(0, 10) + "." : secret) << std::endl;
}
