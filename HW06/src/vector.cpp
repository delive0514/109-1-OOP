#include "vector.h"
// constant member function
int Vector ::dim() const
{
    return _dim;
}

double &Vector ::at(int i) const
{
    return _v[i - 1];
}

void Vector ::subtract(Vector const &v)
{
    if (_dim != v._dim)
    {
        throw string("undefined");
    }
    for (int i = 0; i < _dim; i++)
    {
        _v[i] = _v[i] - v._v[i];
    }
}

void Vector ::add(Vector const &v)
{
    if (_dim != v._dim)
    {
        throw string("undefined");
    }
    for (int i = 0; i < _dim; i++)
    {
        _v[i] = _v[i] + v._v[i];
    }
}

Vector &Vector ::operator=(Vector const &u)
{
    if (_v != NULL)
    {
        delete[] _v;
    }
    copy(u._dim, u._v);
    return *this;
}

Vector Vector ::operator-(Vector const &v) const
{
    if (_dim != v._dim)
    {
        throw string("undefined");
    }
    double *temp;
    temp = new double[_dim];
    for (int i = 0; i < _dim; i++)
    {
        temp[i] = _v[i] - v._v[i];
    }
    return Vector(temp, _dim);
}

Vector Vector ::operator+(Vector const &v) const
{
    if (_dim != v._dim)
    {
        throw string("undefined");
    }
    double *temp;
    temp = new double[_dim];
    for (int i = 0; i < _dim; i++)
    {
        temp[i] = _v[i] + v._v[i];
    }
    return Vector(temp, _dim);
}
double Vector ::dot(Vector input)
{
    double result = 0;
    //input.len also works, beacuse
    // input is an object of the same class
    if (_dim != input.dim())
    {
        throw string("ERROR");
    }
    for (int i = 0; i < _dim; i++)
    {
        // input.content[i] also works, beacuse
        // input is an object of the same class
        result += _v[i] * input._v[i];
    }
    return result;
}

double Vector ::length() const
{
    double s = 0;
    for (int i = 0; i < _dim; i++)
    {
        s += _v[i] * _v[i];
    }
    return sqrt(s);
}
bool Vector ::larger180(Vector input)
{
    return (this->at(1) * input.at(2) - this->at(2) * input.at(1)) >= 0;
}
double Vector ::angle(Vector input)
{
    double sum1 = 0, sum2 = 0;
    sum1 = this->dot(input);
    sum2 = this->length() * input.length();
    if (this->larger180(input))
    {
        return 360 - acos(sum1 / sum2) * 180 / M_PI;
    }
    return acos(sum1 / sum2) * 180 / M_PI;
}
double Vector ::area(Vector inputA, Vector inputB)
{
    double A = (inputA - *this).length();
    double B = (inputB - *this).length();
    double C = (inputA - inputB).length();
    double S = (A + B + C) / 2;
    return sqrt(S * (S - A) * (S - B) * (S - C));
}

Vector Vector ::centroid(Vector vec[], int sides)
{ // static function
    for (int i = 0; i < sides; i++)
    {
        if (vec[i].dim() != 2)
        {
            throw string("Error");
        }
    }
    if (vec == NULL || sides == 0)
    {
        throw string("Error");
    }
    else
    {
        Vector cent(vec[0].dim());
        for (int i = 0; i < sides; i++)
        {
            for (int j = 0; j < cent.dim(); j++)
            {
                cent._v[j] += vec[i]._v[j];
            }
        }
        for (int j = 0; j < cent.dim(); j++)
        {
            cent._v[j] /= sides;
        }
        return cent;
    }
}