#include "Point.hpp"

Fixed area(const Point &a, const Point &b, const Point &c)
{
    Fixed area = (a.getX() * (b.getY() - c.getY()) +
                 b.getX() * (c.getY() - a.getY()) +
                 c.getX() * (a.getY() - b.getY())) / 2;

    return (area < 0) ? area * -1 : area;
}

Point::Point(): x(0), y(0)
{
    return ;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
    return ;
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
    return ;
}

Point::~Point()
{
    return ;
}

Fixed Point::getX() const
{
    return (x);
}

Fixed Point::getY() const
{
    return (y);
}