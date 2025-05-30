#include "Fixed.hpp"
#include "Point.hpp"


int main()
{
    Point a(1, 2);
    Point b(4, 6);
    Point c(5, 2);
    Point point(10, 7);

    std::cout << "Point is " << (bsp(a, b, c, point) ? "inside" : "outside") 
              << " the triangle" << std::endl;
}