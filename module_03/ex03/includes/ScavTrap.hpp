#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap(const std::string &name);
        ScavTrap(ScavTrap &other);
        ScavTrap operator=(ScavTrap &other);
        ~ScavTrap();
        
        void guardGate();

        void attack(const std::string& target);
};