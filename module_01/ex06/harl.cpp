#include "harl.hpp"

void Harl::debug( void )
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese " << std::endl;
}


void Harl::warning( void )
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free" << std::endl;
}

void Harl::info( void )
{
    std::cout << "INFO: cannot believe adding extra bacon costs more mone" << std::endl;
}
void Harl::error( void )
{
    std::cout << "ERROR: his is unacceptable! I want to speak to the manager now. " << std::endl;
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
        case 1:
            (this->*ptr[1])();
        case 2:
            (this->*ptr[2])();
        case 3:
            (this->*ptr[3])();
        default:
            std::cout << "Probably complaining about insignificant problem" << std::endl;
    } 
}