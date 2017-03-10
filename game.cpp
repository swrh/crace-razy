#include "game.hpp"

#include <allegro5/allegro.h>

Game::Game()
{
}

void
Game::update(ALLEGRO_EVENT *event)
{
}

void
Game::draw()
{
    earth.draw();
    track.draw();
}

// vim:set sw=4 ts=4 et:
