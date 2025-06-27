#include "Fixed.hpp"
#include "Point.hpp"


int main()
{
    Point a(0, 0);
    Point b(0, 5);
    Point c(5, 0);
    int px, py;
    std::cout << "enter x location of the point" << std::endl;
    std::cin >> px;

    std::cout << "enter y location of the point" << std::endl;
    std::cin >> py;

    Point point(px, py);
    std::cout << "Point is " << (bsp(a, b, c, point) ? "inside" : "outside") 
              << " the triangle" << std::endl;
}