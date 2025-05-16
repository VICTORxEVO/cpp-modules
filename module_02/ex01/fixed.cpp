#include "fixed.hpp"


Fixed::Fixed(void)
{
    return ;
}

Fixed::Fixed(const int num)
{
    this->setRawBits(num * 256);
}
Fixed::Fixed(const float num)
{
    this->setRawBits(roundf(num * 256));
}

Fixed::Fixed(const Fixed &data)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = data;
}

Fixed::~Fixed(void)
{
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

float Fixed::toFloat(void) const
{
    float res = static_cast<float>(this->rawBits) / 256;
    return (res);
}

int Fixed::toInt(void) const
{
    int res = this->rawBits / 256;
    return (res);
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


std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}