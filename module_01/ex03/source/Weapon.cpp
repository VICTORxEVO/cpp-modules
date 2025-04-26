#include "Weapon.hpp"

Weapon::Weapon(const std::string type) : type(type) {}

const std::string Weapon::getType()
{
    return (this->type);
}

void    Weapon::setType(std::string name)
{
    this->type = name;
}