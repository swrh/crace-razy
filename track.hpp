#if !defined(_TRACK_HPP_)
#define _TRACK_HPP_

#include "object.hpp"
#include "vector.hpp"

#include "allegro/event.hpp"
#include "allegro/polygon.hpp"

#include <vector>

namespace cr {

class
track
: public object
{
private:
    float first_update_time, last_update_time;

    allegro::polygon polygon;

    vector direction;

public:
    track();

    void init_update(double time);
    void update(allegro::event *event, double time);
    void draw();
};

}

#endif // !defined(_TRACK_HPP_)

// vim:set sw=4 ts=4 et:
