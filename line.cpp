#include "line.hpp"

#include <allegro5/allegro_primitives.h>

#include <math.h>

using namespace cr;

line::line(const vertex &base, const vector &vect)
    : x(base.x), y(base.y), a(base.x + cosf(vect.theta) * vect.a), b(base.y + sinf(vect.theta) * vect.a)
{
}

void
line::draw(const allegro::color::allegro_color &color, float thickness) const
{
    al_draw_line(x, y, a, b, color, thickness);
}

// vim:set sw=4 ts=4 et:
