#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string Name;
    public:
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &other);
        ~DiamondTrap();
        DiamondTrap &operator=(const DiamondTrap &other);

        void whoAmI();
        void SetName(std::string Name);
        std::string GetName() const;
        void attack(const std::string& target);
};