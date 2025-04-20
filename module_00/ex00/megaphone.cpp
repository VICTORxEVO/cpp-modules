#include <iostream>

int main(int ac, char *av[])
{
    int i;
    int j;

    i = 0;
    if (ac <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    while (++i < ac)
    {
        j = -1;
        while (av[i][++j])
        {
            if (av[i][j] >= 'a' && av[i][j] <= 'z')
                std::cout << (char)std::toupper(static_cast<unsigned char>(av[i][j]));
            else
                std::cout << av[i][j];
        }
    }
    std::cout << std::endl;
    return 0;
}
