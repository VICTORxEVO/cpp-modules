#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Dog dog;
    const Cat cat;

    dog.makeSound();
    cat.makeSound();
}