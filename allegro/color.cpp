#include "color.hpp"

#include <allegro5/allegro_primitives.h>

using namespace cr::allegro;

color::allegro_color
color::rgb(unsigned char r, unsigned char g, unsigned char b)
{
    return al_map_rgb(r, g, b);
}

// vim:set sw=4 ts=4 et:
