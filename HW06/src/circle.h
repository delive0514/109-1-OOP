#ifndef CIRCLE
#define CIRCLE
#include "shape.h"
#include "vector.h"
#include <string>

using namespace std;
class Circle : public Shape
{
private:
    double _radius;

public:
    Circle() : _radius(0)
    {
        cout << "Constructor in circle" << endl;
    }
    Circle(double radius, string name = "anonymous") : Shape(name)
    { //constructor initialization list
        _radius = radius;
    }
    ~Circle() override
    {
        cout << "Circle deconstructor" << endl;
    }
    double perimeter() const override;
    double area() const override;
};

#endif