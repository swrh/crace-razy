#if !defined(_TRACK_HPP_)
#define _TRACK_HPP_

#include "vector.hpp"

#include <allegro5/allegro_primitives.h>

#include <vector>

class
Track
{
private:
    float first_update_time, last_update_time;

    std::vector<ALLEGRO_VERTEX> vtx;

    Vector direction;

public:
    Track();

    void init_update(double time);
    void update(ALLEGRO_EVENT *event, double time);
    void draw();
};

#endif // !defined(_TRACK_HPP_)

// vim:set sw=4 ts=4 et:
