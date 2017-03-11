#if !defined(_EARTH_HPP_)
#define _EARTH_HPP_

#include <allegro5/allegro.h>

class
Earth
{
public:
    Earth();

    void init_update(double time);
    void update(ALLEGRO_EVENT *event, double time);
    void draw();
};

#endif // !defined(_EARTH_HPP_)

// vim:set sw=4 ts=4 et:
