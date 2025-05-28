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
    std::string info[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    while (++i < 4 && info[i] != level)
        continue;
    switch (i)
    {
        case 0:
            this->debug();
            this->info();
            this->warning();
            this->error();
            break;
        case 1:
            this->info();
            this->warning();
            this->error();
            break;
        case 2:
            this->warning();
            this->error();
            break;
        case 3:
            this->error();
            break;
        default:
            std::cout << "Probably complaining about insignificant problem" << std::endl;
    } 
}