#if !defined(_OBJECT_HPP_)
#define _OBJECT_HPP_

#include "allegro/event.hpp"

namespace cr {

class
object
{
public:
    virtual ~object();

    virtual void init_update(double time) = 0;
    virtual void update(allegro::event *event, double time) = 0;
    virtual void draw() = 0;
};

}

#endif // !defined(_OBJECT_HPP_)

// vim:set sw=4 ts=4 et:
