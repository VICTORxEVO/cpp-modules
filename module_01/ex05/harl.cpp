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
    std::string info[] = {"DEBUG", "WARNING", "INFO", "ERROR"};
    void (Harl::*ptr[4])() = {&Harl::debug, &Harl::warning, &Harl::info, &Harl::error};

    for(int i = 0; i < 4; i++)
    {
        if (info[i] == level)
        {
            (this->*ptr[i])();
            return ;
        }
    }
    std::cout << "Invalid level!" << std::endl;
}