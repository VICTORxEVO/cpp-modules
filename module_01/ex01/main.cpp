#include "Zombie.hpp"

int main ()
{
    Zombie *horde;
    int n = 6;

    horde = zombieHorde(n, "salto7");
    if (horde == NULL)
        return (2);
    for (int i = 0; i < n; ++i)
		horde[i].announce();
	delete[] horde;
	horde = zombieHorde(-10, "Failed");
	horde = zombieHorde(0, "Failed");
	return (0);
}