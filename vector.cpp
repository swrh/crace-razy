#include "vector.hpp"

using namespace cr;

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

// vim:set sw=4 ts=4 et:
