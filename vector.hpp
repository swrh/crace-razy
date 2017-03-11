#if !defined(_VECTOR_HPP_)
#define _VECTOR_HPP_

#include "line.hpp"
#include "vertex.hpp"

struct
Vector
{
    float theta, a;

    Vector();
    Vector(float theta, float a);

    void set(float theta);
    void set(float theta, float a);
    void rotate(float r);

    Line toLine(const Vertex &base) const;
};

#endif // !defined(_VECTOR_HPP_)

// vim:set sw=4 ts=4 et:
