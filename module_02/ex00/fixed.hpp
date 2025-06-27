#pragma once

#include <iostream>

class Fixed {
    private:
        int rawBits;
        static const int fracBits;
    
    public:
        Fixed();
        ~Fixed();
    
        // copy constructor
        Fixed(const Fixed & other);
        
        //copy assignment constructor 
        Fixed & operator=(const Fixed & other);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
    };
