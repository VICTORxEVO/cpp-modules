#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std:string name;
    public:
        DiamondTrap(std::string &name);
        DiamondTrap(const DiamondTrap &other);
        ~DiamondTrap();
        DiamondTrap &operator=(DiamondTrap &other);
};