#include "polygon.hpp"

#include <allegro5/allegro_primitives.h>

#include <stdexcept>

#include <stdlib.h>

using namespace cr::allegro;

polygon::polygon()
{
}

polygon::polygon(polygon::size_type count)
    : data(count)
{
}

polygon::~polygon()
{
}

polygon::size_type
polygon::size() const
{
    return data.size();
}

polygon::allegro_vertex &
polygon::at(polygon::size_type pos)
{
    return data.at(pos);
}

polygon::allegro_vertex &
polygon::operator[](polygon::size_type pos)
{
    return data[pos];
}

void
polygon::draw() const
{
    al_draw_prim(&data[0], 0, 0, 0, data.size(), ALLEGRO_PRIM_LINE_LOOP);
}

// vim:set sw=4 ts=4 et:
