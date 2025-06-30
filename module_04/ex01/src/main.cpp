#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Animal *animals[2] = {new Dog, new Cat};


    delete j;//should not create a leak
    delete i;
    for (int i = 0; i < 2; i++)
        delete animals[i];
}