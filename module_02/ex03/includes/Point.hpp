#pragma once

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &other);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;
        
};

bool bsp(const Point a, const Point b, const Point c, const Point point);
Fixed area(const Point &a, const Point &b, const Point &c);
