#include "game.hpp"

#include <allegro5/allegro.h>

#include <iostream>

Game::Game()
{
}

void
Game::init_update(double time)
{
    std::cout << __func__ << ": " << time << std::endl;
    earth.init_update(time);
    track.init_update(time);
}

void
Game::update(ALLEGRO_EVENT *event, double time)
{
    std::cout << __func__ << ": " << time << " " << std::hex << (event != nullptr ? event->type : 0) << std::endl;
    earth.update(event, time);
    track.update(event, time);
}

void
Game::draw()
{
    earth.draw();
    track.draw();
}

// vim:set sw=4 ts=4 et:
