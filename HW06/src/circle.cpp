#include "circle.h"
double Circle::perimeter() const
{
    return 2 * _radius * M_PI;
}
double Circle::area() const
{
    return _radius * _radius * M_PI;
}