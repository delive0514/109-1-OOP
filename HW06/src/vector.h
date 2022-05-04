#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "bubble_sort.h"
#define M_PI 3.14159265358979323846
using namespace std;
class Vector
{
private:
    int _dim;
    double *_v;
    void copy(int dim, double v[])
    { //initialize
        _v = new double[dim];
        _dim = dim;
        for (int i = 0; i < dim; i++)
        {
            _v[i] = v[i];
        }
    }

public:
    Vector()
    { //default constructor
        _dim = 0;
        _v = new double[_dim];
    }
    Vector(int dim)
    {
        _v = new double[dim];
        _dim = dim;
        for (int i = 0; i < dim; i++)
        {
            _v[i] = 0;
        }
    }
    Vector(double v[], int dim)
    { //constructor
        if (v != NULL)
        {
            copy(dim, v);
        }
        else
        {
            _dim = dim;
            _v = new double[dim];
        }
    }

    Vector(Vector const &v)
    {
        copy(v._dim, v._v);
    }

    // destructor
    ~Vector()
    {
        if (_v != NULL)
        {
            delete[] _v;
        }
    }
    int dim() const;

    double &at(int i) const;

    void subtract(Vector const &v);

    void add(Vector const &v);

    Vector &operator=(Vector const &u);

    Vector operator-(Vector const &v) const;

    Vector operator+(Vector const &v) const;
    double dot(Vector input);

    double length() const;
    bool larger180(Vector input);
    double angle(Vector input);
    double area(Vector inputA, Vector inputB);

    static Vector centroid(Vector vectors[], int num);
};
class angleComparator
{
private:
    Vector _a;
    Vector _b;

public:
    angleComparator()
    {
    }

    angleComparator(Vector &a, Vector &b)
    {
        _a = a;
        _b = b;
    }

    bool operator()(Vector &u, Vector &v)
    {
        return _b.angle(u - _a) < _b.angle(v - _a);
    }
};
#endif
