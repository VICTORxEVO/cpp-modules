#ifndef PHONEBOOK
# define PHONEBOOK

#include <string>
#include <iostream>


class contact
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
    contact contacts[8];
    public:
        int index ;    

        void add();
        void search();
};










#endif