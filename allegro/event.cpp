#include "event.hpp"

#include <allegro5/allegro_primitives.h>

#include <stdexcept>

#include <stdlib.h>

using namespace cr::allegro;

event::event()
{
    data = new allegro_event();
}

event::~event()
{
    delete data;
}

event::allegro_event &
event::get()
{
    return *data;
}

// vim:set sw=4 ts=4 et:
