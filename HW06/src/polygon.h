#ifndef POLYGON
#define POLYGON
#include "vector.h"
#include "shape.h"

class Polygon : public Shape
{
private:
    int _numVertices;
    Vector *_vertices;
public:
    Polygon()
    {
        _numVertices = 0;
        _vertices = new Vector[_numVertices];
    }
    Polygon(Vector *input, int inputVerties)
    {
        _numVertices = inputVerties;
        _vertices = new Vector[_numVertices];
        Vector c = Vector::centroid(input, inputVerties);
        Vector b = input[0] - c;
        angleComparator comp = angleComparator(c, b);
        //std::sort(input,input+numVertices,comp);
        BubbleSort(input, input + inputVerties, comp);
        for (int i = 0; i < _numVertices; i++)
        {
            _vertices[i] = input[i];
        }
    }
    int getNumberOfVerties() const;
    double perimeter() const override;
    double area() const override;
    Vector centroid();
};
#endif