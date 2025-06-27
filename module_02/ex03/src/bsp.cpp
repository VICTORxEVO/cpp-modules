#include "Point.hpp"


bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    
    Fixed total_area = area(a, b, c);
    //calculate area of points PBC, APC, ABP
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);
    
    if (area1 > 0 || area2 > 0 || area3 > 0)
        return ((area1 + area2 + area3) == total_area);
    return (false);
}