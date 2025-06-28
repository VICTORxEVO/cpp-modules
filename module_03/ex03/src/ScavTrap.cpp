#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << name << " has been created with "
              << hit_points << " HP, " << energy_points << " EP, and "
              << attack_damage << " AD." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap" << Name << "copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);  // Call base class assignment operator
    std::cout << "ScavTrap" << Name << "assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " has been destroyed!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name
    << " has entered in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hit_points <= 0)
    {
        std::cout << "ScavTrap " << Name << " is dead and can't attack!" << std::endl;
        return;
    }
    if (energy_points <= 0)
    {
        std::cout << "ScavTrap " << Name << " has no energy left to attack!" << std::endl;
        return;
    }
    energy_points--;
    std::cout << "ScavTrap " << Name << " attacks " << target << ", causing "
              << attack_damage << " points of damage!" << std::endl;
}
