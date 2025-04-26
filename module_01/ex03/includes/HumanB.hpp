#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <Weapon.hpp>

class HumanB
{
    private:
        std::string name;
        bool has_weapon;
        Weapon *weapon;
    
    public:
        //doesn't always have a weapon
        HumanB(std::string name);
        void attack(void);
        void setWeapon(Weapon &w);

};














#endif