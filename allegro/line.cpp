#include "line.hpp"

#include <allegro5/allegro_primitives.h>

#include <math.h>

using namespace cr::allegro;

line::line(const vertex &base, const vector &vect)
    : polygon(2)
{
    at(0).x = base.x;
    at(0).y = base.y;
    at(1).x = base.x + cosf(vect.theta) * vect.a;
    at(1).y = base.y + sinf(vect.theta) * vect.a;
}

void
line::draw(const allegro::color::allegro_color &color, float thickness) const
{
    al_draw_line(at(0).x, at(0).y, at(1).x, at(1).y, color, thickness);
}

// vim:set sw=4 ts=4 et:
