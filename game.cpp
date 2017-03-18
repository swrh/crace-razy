#include "game.hpp"

#include <allegro5/allegro.h>

#include <iostream>
#include <memory>

using namespace cr;

game::game()
{
    objects.push_back(std::make_shared<earth>());
    objects.push_back(std::make_shared<track>());
}

void
game::init_update(double time)
{
    std::cout << __func__ << ": " << time << std::endl;

    for (std::shared_ptr<object> &o : objects) {
        o->init_update(time);
    }
}

void
game::update(allegro::event *event, double time)
{
    std::cout << __func__ << ": " << time << " " << std::hex << (event != nullptr ? event->get().type : 0) << std::endl;

    for (std::shared_ptr<object> &o : objects) {
        o->update(event, time);
    }
}

void
game::draw()
{
    for (std::shared_ptr<object> &o : objects) {
        o->draw();
    }
}

// vim:set sw=4 ts=4 et:
