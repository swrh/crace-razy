#if !defined(_EARTH_HPP_)
#define _EARTH_HPP_

#include "allegro/event.hpp"

#include "object.hpp"

namespace cr {

class
earth
: public object
{
public:
    earth();

    void init_update(double time);
    void update(allegro::event *event, double time);
    void draw();
};

}

#endif // !defined(_EARTH_HPP_)

// vim:set sw=4 ts=4 et:
