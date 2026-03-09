#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac < 2 || ac > 2)
    {
        std::cerr << "Usage: ./RPN \"<numbers>\"" << std::endl;
        return (1);
    }
    try
    {
        Rpn stack(av[1]);
        std::cout << stack << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}