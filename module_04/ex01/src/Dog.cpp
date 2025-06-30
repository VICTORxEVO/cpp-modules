#include "../includes/Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{ 
    brain = new Brain(*other.brain);  // Deep copy
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;  // Clean up existing brain
        brain = new Brain(*other.brain);  // Deep copy
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;  // Free the allocated memory
}

void Dog::makeSound() const
{
    std::cout << "wooooooooof" << std::endl;
}

