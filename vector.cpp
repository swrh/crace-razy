#include "vector.hpp"

#include <math.h>

using cr::line;
using cr::vector;

vector::vector()
    : theta(0), a(0)
{
}

vector::vector(float theta, float a)
    : theta(theta), a(a)
{
}

void
vector::set(float theta)
{
    this->theta = theta;
}

void
vector::set(float theta, float a)
{
    this->theta = theta;
    this->a = a;
}

/**
 * Rotate clockwise.
 * @param rad Angle in radian.
 */
void
vector::rotate(float rad)
{
    theta += rad;
}

line
vector::to_line(const vertex &base) const
{
    return line(base.x, base.y, base.x + cosf(theta) * a, base.y + sinf(theta) * a);
}

// vim:set sw=4 ts=4 et:
