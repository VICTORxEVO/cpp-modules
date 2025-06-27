#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
    return ;
}

ClapTrap::ClapTrap(const std::string &name)
{
	this->Name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "ClapTrap "<< name << " has been created !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    this->Name = other.Name;
    this->hit_points = other.hit_points;
    this->attack_damage = other.attack_damage;
    this->energy_points = other.energy_points;
    std::cout << "ClapTrap " << Name << " has been copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{ 
    if (this != &other)
    {
        this->Name = other.Name;
        this->hit_points = other.hit_points;
        this->attack_damage = other.attack_damage;
        this->energy_points = other.energy_points;
    }
    std::cout << "ClapTrap " << Name << " has been assigned!" << std::endl;
    return *this;
}



ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap "<< Name << " has been destroyed !" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (hit_points <= 0)
    {
        std::cout << "ClapTrap " << Name << " is dead and can't attack!" << std::endl;
        return;
    }
    if (energy_points <= 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy left to attack!" << std::endl;
        return;
    }
    energy_points--;
    std::cout << "ClapTrap " << Name << " attacks " << target << ", causing "
              << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points <= 0) {
        std::cout << "ClapTrap " << Name << " is already dead!" << std::endl;
        return;
    }
    hit_points -= amount;
    if (hit_points < 0)
        hit_points = 0;
    std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage! "
              << "Remaining hp: " << hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit_points <= 0) {
        std::cout << "ClapTrap " << Name << " is dead and can't be repaired!" << std::endl;
        return;
    }
    if (energy_points <= 0) {
        std::cout << "ClapTrap " << Name << " has no energy left to repair!" << std::endl;
        return;
    }
    hit_points += amount;
    energy_points--;
    std::cout << "ClapTrap " << Name << " repairs itself, recovering " << amount
              << " hit points! Current hp: " << hit_points << std::endl;
}

