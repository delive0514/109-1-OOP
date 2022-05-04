#include "polygon.h"
int Polygon ::getNumberOfVerties() const
{
    return _numVertices;
}
double Polygon ::perimeter() const
{
    double perimeter = 0;
    for (int i = 0; i < _numVertices; i++)
    {
        perimeter += (_vertices[(i + 1) % _numVertices] - _vertices[i]).length();
    }
    return perimeter;
}
double Polygon ::area() const
{
    double area = 0;
    for (int i = 0; i < (_numVertices - 2); i++)
    {
        area += _vertices[0].area(_vertices[i + 1], _vertices[i + 2]);
    }
    return area;
}
Vector Polygon ::centroid()
{
    Vector sum(2);
    for (int i = 0; i < _numVertices; i++)
    {
        sum.at(1) += _vertices[i].at(1);
        sum.at(2) += _vertices[i].at(2);
    }
    sum.at(1) /= _numVertices;
    sum.at(2) /= _numVertices;
    return sum;
}