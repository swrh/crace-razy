#include "track.hpp"

#include "allegro/color.hpp"
#include "allegro/line.hpp"

#include <allegro5/allegro_primitives.h>

#include <math.h>

using namespace cr;

track::track()
    : first_update_time(0), last_update_time(0), polygon(13)
{
    for (int ii = 0; ii < polygon.size(); ii++) {
        allegro::polygon::allegro_vertex &v = polygon.at(ii);

        float x, y;
        x = 200 + 200 * cosf((float)ii / 13.0f * 2 * ALLEGRO_PI);
        y = 200 + 200 * sinf((float)ii / 13.0f * 2 * ALLEGRO_PI);

        v.x = x; v.y = y; v.z = 0;
        v.color = allegro::color::rgb((ii + 1) % 3 * 64, (ii + 2) % 3 * 64, (ii) % 3 * 64);;
    }

    direction.set(0, 180);
}

void
track::init_update(double time)
{
    first_update_time = time;
    last_update_time = time;
}

void
track::update(allegro::event *event, double time)
{
    direction.set(floorf(time - first_update_time) * (2 * ALLEGRO_PI) / 60. - ALLEGRO_PI / 2);
    last_update_time = time;
}

void
track::draw()
{
    allegro::line line(allegro::vertex(200, 200), direction);
    line.draw(allegro::color::rgb(100, 100, 100), 10);
    polygon.draw();
}

// vim:set sw=4 ts=4 et:
