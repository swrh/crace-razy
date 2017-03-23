#if !defined(_LINE_HPP_)
#define _LINE_HPP_

#include "vector.hpp"
#include "vertex.hpp"

#include "allegro/color.hpp"

namespace cr {

struct
line
{
    float x, y, a, b;

    line(const vertex &base, const vector &vect);

    void draw(const allegro::color::allegro_color &color, float thickness) const;
};

}

#endif // !defined(_LINE_HPP_)

// vim:set sw=4 ts=4 et:
