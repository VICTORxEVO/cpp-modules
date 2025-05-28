#include "Fixed.hpp"

Fixed area(const Point &a, const Point &b, const Point &c)
{
    Fixed area = (a.getX() * (b.getY() - c.getY()) +
                 b.getX() * (c.getY() - a.getY()) +
                 c.getX() * (a.getY() - b.getY())) / 2;

    // Fixed area = ((b.getX() - a.getX()) * (c.getY() - a.getY()) -
    //              (c.getX() - a.getX()) * (b.getY() - a.getY())) / 2;
    return (area < 0) ? area * -1 : area;
}

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point)
{
    
    Fixed total_area = area(a, b, c);
    //calculate area of points PBC, APC, ABP
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);
    
    if (area1 > 0, area2 > 0, area3 > 0)
        return ((area1 + area2 + area3) == total_area);
    return (false);
}
int main()
{
    Point a(1, 2);
    Point b(4, 6);
    Point c(5, 2);
    Point point(10, 7);

    std::cout << "Point is " << (bsp(a, b, c, point) ? "inside" : "outside") 
              << " the triangle" << std::endl;
}