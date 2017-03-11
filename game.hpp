#if !defined(_GAME_HPP_)
#define _GAME_HPP_

#include "earth.hpp"
#include "track.hpp"

#include <allegro5/allegro.h>

class
Game
{
private:
    Earth earth;
    Track track;

public:
    Game();

    void init_update(double time);
    void update(ALLEGRO_EVENT *event, double time);
    void draw();
};

#endif // !defined(_GAME_HPP_)

// vim:set sw=4 ts=4 et:
