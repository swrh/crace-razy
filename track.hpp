#if !defined(_TRACK_HPP_)
#define _TRACK_HPP_

#include <allegro5/allegro_primitives.h>

#include <vector>

class
Track
{
private:
    std::vector<ALLEGRO_VERTEX> vtx;

public:
    Track();

    void draw();
};

#endif // !defined(_TRACK_HPP_)

// vim:set sw=4 ts=4 et:
