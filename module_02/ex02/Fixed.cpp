#include "Fixed.hpp"

const int Fixed::fracBits = 8; 


Fixed::Fixed()
{
    this->rawBits = 0;
}

Fixed::Fixed(const int nbr)
{
    this->rawBits = nbr << Fixed::fracBits;
}

Fixed::Fixed(const float nbr)
{
    this->rawBits = static_cast<int>(roundf(nbr * (1 << fracBits)));
}
Fixed::~Fixed()
{

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

Fixed::Fixed(const Fixed & other)
{
    *this = other;
}
int Fixed::getRawBits( void ) const
{
    return (this->rawBits); 
}

void Fixed::setRawBits( int const raw )
{
    this->rawBits = raw;
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->rawBits > other.rawBits);
}
bool Fixed::operator<(const Fixed& other) const
{
    return (this->rawBits < other.rawBits);
}
bool Fixed::operator!=(const Fixed& other) const
{
    return (this->rawBits != other.rawBits);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->rawBits <= other.rawBits);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->rawBits >= other.rawBits);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->rawBits == other.rawBits);
}

Fixed & Fixed::operator=(const Fixed& other) 
{
    if (this != &other)
    {
        this->rawBits = other.getRawBits();
    }
    return (*this);
}

Fixed Fixed::operator+(const Fixed & other) const
{
    Fixed res;
    long tmp = (long)this->rawBits + (long)other.rawBits;
    if (tmp > INT_MAX || tmp < INT_MAX)
        std::cerr << "Warning: overflow in addition" << std::endl;
    res.setRawBits((int)tmp);
    return (res);
}

Fixed Fixed::operator-(const Fixed & other) const
{
    Fixed res;
    long tmp = (long)this->rawBits - (long)other.rawBits;
    if (tmp > INT_MAX || tmp < INT_MIN)
        std::cerr << "Warning: overflow in subtraction" << std::endl;
    res.setRawBits((int)tmp);
    return (res);
}
Fixed Fixed::operator*(const Fixed & other) const
{
    Fixed res;
    long tmp = (long)this->rawBits * (long)other.rawBits;
    if (tmp > INT_MAX || tmp < INT_MIN)
        std::cerr << "Warning: overflow in multiplication" << std::endl;
    res.setRawBits((int)(tmp >> fracBits));
    return (res);
}
Fixed Fixed::operator/(const Fixed & other) const
{
    Fixed res;
    if (other.rawBits == 0)
    {
        std::cerr << "Warning: division by zero" << std::endl;
        return (res);
    }
    long tmp = (long)this->rawBits << fracBits / (long)other.rawBits;
    if (tmp > INT_MAX || tmp < INT_MIN)
        std::cerr << "Warning: overflow in division" << std::endl;
    res.setRawBits((int)tmp);
    return (res);
}

Fixed Fixed::operator++()
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed Fixed:: operator--()
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->setRawBits(this->getRawBits() + 1);
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->setRawBits(this->getRawBits() - 1);
    return (tmp);
}

// Min function (non-const version)
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

// Min function (const version)
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}
// Max function (non-const version)
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}
// Max function (const version)
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

std::ostream & operator<<(std::ostream & o, Fixed const & obj)
{
    o << obj.toFloat();
    return (o);
}