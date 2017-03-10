#if !defined(_GAME_HPP_)
#define _GAME_HPP_

#include "earth.hpp"
#include "track.hpp"

union ALLEGRO_EVENT;

class
Game
{
private:
    Earth earth;
    Track track;

public:
    Game();

    void update(ALLEGRO_EVENT *event);
    void draw();
};

#endif // !defined(_GAME_HPP_)

// vim:set sw=4 ts=4 et:
