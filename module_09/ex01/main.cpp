#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./RPN \"<numbers>\"" << std::endl;
        return (1);
    }
    try
    {
        Rpn stack(av[1]);
        std::cout << "res -> " << stack << std::endl;
        stack.compute(av[1]);
        std::cout << "res using methode -> " << stack << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}