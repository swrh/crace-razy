#include "vertex.hpp"

Vertex::Vertex()
    : x(0), y(0)
{
}

Vertex::Vertex(float x, float y)
    : x(x), y(y)
{
}

void
Vertex::set(float x, float y)
{
    this->x = x;
    this->y = y;
}

void
Vertex::move(float x, float y)
{
    this->x += x;
    this->y += y;
}

void
Vertex::move(const Vertex &p)
{
    this->x += p.x;
    this->y += p.y;
}

// vim:set sw=4 ts=4 et:
