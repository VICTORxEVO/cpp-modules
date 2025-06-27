#pragma once

#include <iostream>
#include <string>


class ClapTrap
{
    private:
        std::string Name;
        int hit_points;
        int energy_points;
        int attack_damage;
    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &other);
        ClapTrap & operator=(ClapTrap &other)

        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};