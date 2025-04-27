#include "harl.hpp"

void Harl::debug( void )
{
    std::cout << "DEBUG: 7XL-double-cheese" << std::endl;
}


void Harl::warning( void )
{
    std::cout << "WARNING: extra bacon for free" << std::endl;
}

void Harl::info( void )
{
    std::cout << "INFO: adding extra bacon" << std::endl;
}
void Harl::error( void )
{
    std::cout << "ERROR: This is unacceptable! " << std::endl;
}

void Harl::complain(std::string level)
{
    int i = -1;
    std::string info[] = {"DEBUG", "WARNING", "INFO", "ERROR"};
    void (Harl::*ptr[4])() = {&Harl::debug, &Harl::warning, &Harl::info, &Harl::error};

    while (++i < 4 && info[i] != level)
        continue;
    switch (i)
    {
        case 0:
            (this->*ptr[0])();
            break;
        case 1:
            (this->*ptr[1])();
            break;
        case 2:
            (this->*ptr[2])();
            break;
        case 3:
            (this->*ptr[3])();
            break;
        default:
            std::cout << "Probably complaining about insignificant problem" << std::endl;
    } 
}