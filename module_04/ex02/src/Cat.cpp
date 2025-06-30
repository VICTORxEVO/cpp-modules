#include "../includes/Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    brain = new Brain(*other.brain);  // Deep copy
}

Cat &Cat::operator=(const Cat &other)
{
    Animal::operator=(other);
    if (this != &other)
    {
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "meawwwwwwwwwww" << std::endl;
}