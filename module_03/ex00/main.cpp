#include "ClapTrap.hpp"

int main()
{
    ClapTrap bob("bob");
    ClapTrap mike("mike");

    bob.attack("minions");
    mike.attack("minions");

    bob.takeDamage(3);
    mike.beRepaired(5);
    
    bob.beRepaired(4);
    mike.takeDamage(10);
}