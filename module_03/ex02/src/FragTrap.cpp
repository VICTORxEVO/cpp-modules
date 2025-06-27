#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap " << name << " has been created with "
              << hit_points << " HP, " << energy_points << " EP, and "
              << attack_damage << " AD." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    return ;
}

FragTrap & FragTrap::operator=(FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other); // Assign base class members
    }
    std::cout << "FragTrap " << Name << " has been assigned!" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap "<< Name << " has been destroyed !" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "high fives !!" << std::endl;
}