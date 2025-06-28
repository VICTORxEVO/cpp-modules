#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), Name(name)
{
    hit_points = FragTrap::hit_points;       
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage; 
    std::cout << "DiamondTrap " << name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), Name(other.Name)
{
    std::cout << "DiamondTrap " << Name << " copied!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << Name << " has been destroyed !" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        Name = other.Name;
    }
    std::cout << "DiamondTrap " << Name << " has been assigned!" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << Name << " and ClapTrap " << ClapTrap::Name << std::endl;
}

void DiamondTrap::SetName(std::string Name)
{
    this->Name = Name;
}

std::string DiamondTrap::GetName() const
{
    return (this->Name);
}