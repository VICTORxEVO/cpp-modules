#include "Zombie.hpp"


Zombie::Zombie(std::string name)
{
    this->name  = name;
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " -> destroyed!"  << std::endl; 
    return ;
}

void Zombie::announce(void)
{
    std::cout << this->name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}