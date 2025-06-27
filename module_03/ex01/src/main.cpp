#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap bob("bob");
    ClapTrap mike("mike");
    ScavTrap jim("jim");

    bob.attack("minions");
    mike.attack("minions");
    jim.attack("minion");

    bob.takeDamage(3);
    jim.takeDamage(10);
    mike.beRepaired(5);
    
    bob.beRepaired(4);
    jim.beRepaired(5);
    mike.takeDamage(10);
}