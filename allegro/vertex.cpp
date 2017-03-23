#include "vertex.hpp"

using namespace cr::allegro;

vertex::vertex()
    : x(0), y(0)
{
}

vertex::vertex(float x, float y)
    : x(x), y(y)
{
}

void
vertex::set(float x, float y)
{
    this->x = x;
    this->y = y;
}

void
vertex::move(float x, float y)
{
    this->x += x;
    this->y += y;
}

void
vertex::move(const vertex &p)
{
    this->x += p.x;
    this->y += p.y;
}

// vim:set sw=4 ts=4 et:
