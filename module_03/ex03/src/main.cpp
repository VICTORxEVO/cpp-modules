#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    ClapTrap bob("bob");
    ClapTrap mike("mike");
    ScavTrap jim("jim");
    FragTrap jax("jax");
    DiamondTrap Diam("diam")

    bob.attack("minions");
    mike.attack("minions");
    jim.attack("minion");
    jax.attack("minion");
    

    bob.takeDamage(3);
    jim.takeDamage(10);
    mike.takeDamage(10);
    jax.takeDamage(20);
    
    mike.beRepaired(5);
    bob.beRepaired(4);
    jim.beRepaired(5);
    jax.beRepaired(6);
}