#if !defined(_GAME_HPP_)
#define _GAME_HPP_

#include "earth.hpp"
#include "track.hpp"

#include "allegro/event.hpp"

#include <list>
#include <memory>

namespace cr {

class
game
{
private:
    std::list<std::shared_ptr<object> > objects;

public:
    game();

    void init_update(double time);
    void update(allegro::event *event, double time);
    void draw();
};

}

#endif // !defined(_GAME_HPP_)

// vim:set sw=4 ts=4 et:
