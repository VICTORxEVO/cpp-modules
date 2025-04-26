#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &weapon;
    
    public:
        //always has weapon
        HumanA(std::string name, Weapon &weapon);
        void attack(void);
};

















#endif