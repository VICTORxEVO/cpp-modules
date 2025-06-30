#pragma once

#include <string>
#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();
        
        virtual void makeSound() const = 0;
        void setType(std::string type);
        std::string getType() const;
    protected:
        std::string type;

};