#include "earth.hpp"

#include <allegro5/allegro.h>

Earth::Earth()
{
}

void
Earth::draw()
{
    //al_clear_to_color(al_map_rgb(25, 100, 50));
    al_clear_to_color(al_map_rgb(0, 0, 0));
}

// vim:set sw=4 ts=4 et:
