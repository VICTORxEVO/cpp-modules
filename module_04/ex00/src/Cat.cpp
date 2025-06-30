#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meawwwwwwwwwww" << std::endl;
}