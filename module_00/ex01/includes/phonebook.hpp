#ifndef PHONEBOOK
# define PHONEBOOK

#include <string>
#include <iostream>


class contacts
{
    std::string info[4];
    public:
        void WriteFirstName(std::string str);
        void WriteLastName(std::string str);
        void WriteNickName(std::string str);
        std::string GetFirstName() const;
        std::string GetLastName() const;
        std::string GetNickName() const;

};



class phonebook
{
    contacts contacts[8];
    public:
        char index {0};    

        void add();
        void search();
        void display();
};










#endif