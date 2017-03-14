#include "event.hpp"

#include <allegro5/allegro_primitives.h>

#include <stdexcept>

#include <stdlib.h>

using cr::allegro::event;

event::event()
{
    data = static_cast<ALLEGRO_EVENT *>(malloc(sizeof(ALLEGRO_EVENT)));
    if (data == nullptr)
        throw std::bad_alloc();
}

event::~event()
{
    free(data);
}

ALLEGRO_EVENT &
event::get()
{
    return *data;
}

// vim:set sw=4 ts=4 et:
