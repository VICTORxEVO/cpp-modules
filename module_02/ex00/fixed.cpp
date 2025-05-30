#include "fixed.hpp"


Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->rawBits = 0;
}

Fixed::Fixed(const Fixed &data)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = data;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->rawBits = raw;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->rawBits); 
}

Fixed & Fixed::operator=(const Fixed& other) 
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->rawBits = other.getRawBits();
    }
    return (*this);
}