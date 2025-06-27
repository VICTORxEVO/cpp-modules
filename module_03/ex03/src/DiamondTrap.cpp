#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), Name(name)
{
    hit_points = FragTrap::hit_points;       
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage; 
    std::cout << "DiamondTrap " << name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), Name(other.Name)
{
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    std::cout << "DiamondTrap " << Name << " copied!" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        Name = other.Name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
    }
    std::cout << "DiamondTrap " << Name << " has been assigned!" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << Name << " and ClapTrap " << ClapTrap::Name << std::endl;
}

void DiamondTrap::SetName(std::string Name) const
{
    this->Name = Name
}