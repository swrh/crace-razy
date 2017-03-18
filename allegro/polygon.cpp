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

polygon::vertex &
polygon::at(polygon::size_type pos)
{
    return data.at(pos);
}

polygon::vertex &
polygon::operator[](polygon::size_type pos)
{
    return data[pos];
}

// vim:set sw=4 ts=4 et:
