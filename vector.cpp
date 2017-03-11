#include "vector.hpp"

#include <math.h>

Vector::Vector()
    : theta(0), a(0)
{
}

Vector::Vector(float theta, float a)
    : theta(theta), a(a)
{
}

void
Vector::set(float theta)
{
    this->theta = theta;
}

void
Vector::set(float theta, float a)
{
    this->theta = theta;
    this->a = a;
}

/**
 * Rotate clockwise.
 * @param rad Angle in radian.
 */
void
Vector::rotate(float rad)
{
    theta += rad;
}

Line
Vector::toLine(const Vertex &base) const
{
    return Line(base.x, base.y, base.x + cosf(theta) * a, base.y + sinf(theta) * a);
}

// vim:set sw=4 ts=4 et:
