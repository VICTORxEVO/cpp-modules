#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    BitcoinExchange btc;

    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    if (!btc.loadDatabase("data.csv"))
    {
        std::cerr << "Error: could not open database." << std::endl;
        return 1;
    }

    btc.processInput(argv[1]);

    return 0;
}