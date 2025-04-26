#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->has_weapon = false;
};


void HumanB::setWeapon(Weapon &wp)
{
    this->weapon = &wp; 
    this->has_weapon = true;
}

void HumanB::attack(void)
{
    if (has_weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}