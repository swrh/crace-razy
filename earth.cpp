#include "earth.hpp"

#include "allegro/color.hpp"

#include <allegro5/allegro.h>

using namespace cr;

earth::earth()
{
}

void
earth::init_update(double time)
{
}

void
earth::update(allegro::event *event, double time)
{
}

void
earth::draw()
{
    al_clear_to_color(allegro::color::rgb(0, 100, 50));
}

// vim:set sw=4 ts=4 et:
