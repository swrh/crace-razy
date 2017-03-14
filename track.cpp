#include "track.hpp"

#include "line.hpp"

#include <allegro5/allegro_primitives.h>

#include <math.h>

using cr::track;

track::track()
    : first_update_time(0), last_update_time(0), polygon(13)
{
    for (int ii = 0; ii < polygon.size(); ii++) {
        allegro::polygon::vertex &v = polygon.at(ii);

        float x, y;
        x = 200 + 200 * cosf((float)ii / 13.0f * 2 * ALLEGRO_PI);
        y = 200 + 200 * sinf((float)ii / 13.0f * 2 * ALLEGRO_PI);

        v.x = x; v.y = y; v.z = 0;
        v.color = al_map_rgb((ii + 1) % 3 * 64, (ii + 2) % 3 * 64, (ii) % 3 * 64);;
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
    line line = direction.to_line(vertex(200, 200));
    al_draw_line(line.x, line.y, line.a, line.b, al_map_rgb(100, 100, 100), 10);
    al_draw_prim(&polygon[0], 0, 0, 0, polygon.size(), ALLEGRO_PRIM_LINE_LOOP);
}

// vim:set sw=4 ts=4 et:
