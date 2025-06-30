#pragma once

#include <string>
#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        ~Animal();
        
        virtual void makeSound() const;
        void setType(std::string type);
        std::string getType() const;
    protected:
        std::string type;

};