#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal &other);
        ~WrongAnimal();
        
        void makeSound() const ;
        void setType(std::string type);
        std::string getType() const;
    protected:
        std::string type;

};