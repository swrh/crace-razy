#if !defined(_VECTOR_HPP_)
#define _VECTOR_HPP_

#include "line.hpp"
#include "vertex.hpp"

namespace cr {

struct
vector
{
    float theta, a;

    vector();
    vector(float theta, float a);

    void set(float theta);
    void set(float theta, float a);
    void rotate(float r);

    line to_line(const vertex &base) const;
};

}

#endif // !defined(_VECTOR_HPP_)

// vim:set sw=4 ts=4 et:
