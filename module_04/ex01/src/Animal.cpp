#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
    type = "Animal";
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::setType(std::string type)
{
    this->type = type;
}
std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "animal sound !!" << std::endl;
}