#include "phonebook.hpp"
#include <iomanip> // Include for std::setw
#include <string>  // Include for std::string

void phonebook::add(void)
{
    std::string fname, lname, nname, pn, secret;

    std::cout << "Enter First name" << std::endl;
    std::getline(std::cin, fname);
    std::cout << "Enter " << fname << "'s Last name" << std::endl;
    std::getline(std::cin, lname);
    std::cout << "Enter " << fname << "'s Nick name" << std::endl;
    std::getline(std::cin, nname);
    std::cout << "Enter " << fname << "'s phone number" << std::endl;
    std::getline(std::cin, pn);
    std::cout << "Enter " << fname << "'s darkest secret" << std::endl;
    std::getline(std::cin, secret);
    if (std::cin.eof())
        return ;
    if (fname.empty() || lname.empty() || nname.empty() || pn.empty() || secret.empty())
    {
        std::cout << "All fields are required!" << std::endl;
        return ;
    }
    this->contacts[this->index].SetFirstName(fname);
    this->contacts[this->index].SetLastName(lname);
    this->contacts[this->index].SetNickName(nname);
    this->contacts[this->index].SetPhoneNum(pn);
    this->contacts[this->index].SetSecret(secret);

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
    
    std::cout << "First name    :"<< (firstname.length() > 10 ? firstname.substr(0, 10) + "." : firstname) << std::endl;
    std::cout << "Last name     :" << (lastname.length() > 10 ? lastname.substr(0, 10) + "." : lastname) << std::endl;
    std::cout << "nick name     :" << (nickname.length() > 10 ? nickname.substr(0, 10) + "." : nickname) << std::endl;
    std::cout << "phone number  :" << (phonenum.length() > 10 ? phonenum.substr(0, 10) + "." : phonenum) << std::endl;
    std::cout << "darkest secret:" << (secret.length() > 10 ? secret.substr(0, 10) + "." : secret) << std::endl;
}
