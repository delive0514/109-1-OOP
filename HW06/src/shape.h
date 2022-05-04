#ifndef SHAPE
#define SHAPE
#include "vector.h"
#include <string>

class Shape
{
protected:
    string _name;

public:
    Shape()
    {
        _name = "nothing";
    }
    Shape(string name)
    {
        _name = name;
    }
    virtual ~Shape()
    {
    }
    virtual double area() const = 0; // virtual == no definition
    virtual double perimeter() const = 0;
    string getName() const;
};
template <class RandomAccessIterator, class Condition>
std ::vector<Shape *> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond)
{
    std::vector<Shape *> result;
    while (begin != end)
    {
        if (cond(*(begin)))
        {
            result.push_back(*(begin));
        }
        begin = begin + 1;
    }
    return result;
}
#endif