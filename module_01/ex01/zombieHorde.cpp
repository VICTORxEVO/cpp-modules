#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 1)
    {
        std::cout << "Horde must have more than 1 zombie" << std::endl;
        return (NULL);
    }
    Zombie *horde = new Zombie[N];
    if (horde == NULL)
    {
        std::cout << "Memory Allocation failed." << std::endl;
		return (NULL);
    }
    for (int i = 0; i < N;i++)
        horde[i].set_name(name);
    return(horde);
}