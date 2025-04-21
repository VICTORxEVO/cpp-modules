#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombie = newZombie("the bob Zombie");
	randomChump("brainz Zombie");
	zombie->announce();
	delete zombie;
	return (0);
}