#if !defined(_EARTH_HPP_)
#define _EARTH_HPP_

#include "object.hpp"

#include <allegro5/allegro.h>

namespace cr {

class
earth
: public object
{
public:
    earth();

    void init_update(double time);
    void update(ALLEGRO_EVENT *event, double time);
    void draw();
};

}

#endif // !defined(_EARTH_HPP_)

// vim:set sw=4 ts=4 et:
