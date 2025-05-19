#ifndef PHONEBOOK
# define PHONEBOOK

#include <string>
#include <iostream>
#include <cstdlib>

class contact
{
    private:
        std::string info[6];
    public:
        void SetFirstName(std::string str);
        void SetLastName(std::string str);
        void SetNickName(std::string str);
        void SetPhoneNum(std::string str);
        void SetSecret(std::string str);
        std::string GetFirstName() const;
        std::string GetLastName() const;
        std::string GetNickName() const;
        std::string GetPhoneNum() const;
        std::string GetSecret() const;
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