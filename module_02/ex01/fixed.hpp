#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int rawBits;
        static const int fracBits;
    
    public:
        Fixed();
        ~Fixed();;
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed & other);
        
        float toFloat(void) const;
        int toInt(void) const;
        
        int getRawBits(void) const;
        void setRawBits(int const raw);

        Fixed & operator=(const Fixed & other);
    };
    
    std::ostream& operator<<(std::ostream& os, const Fixed& fixed);




#endif