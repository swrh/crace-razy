#include "track.hpp"

#include "line.hpp"

#include <allegro5/allegro_primitives.h>

#include <math.h>

Track::Track()
    : first_update_time(0), last_update_time(0)
{
    vtx.resize(13);

    for (int ii = 0; ii < vtx.size(); ii++) {
         ALLEGRO_VERTEX &v = vtx.at(ii);

        float x, y;
        x = 200 + 200 * cosf((float)ii / 13.0f * 2 * ALLEGRO_PI);
        y = 200 + 200 * sinf((float)ii / 13.0f * 2 * ALLEGRO_PI);

        v.x = x; v.y = y; v.z = 0;
        v.color = al_map_rgb((ii + 1) % 3 * 64, (ii + 2) % 3 * 64, (ii) % 3 * 64);;
    }

    direction.set(0, 180);
}

void
Track::init_update(double time)
{
    first_update_time = time;
    last_update_time = time;
}

void
Track::update(ALLEGRO_EVENT *event, double time)
{
    direction.set(floorf(time - first_update_time) * (2 * ALLEGRO_PI) / 60. - ALLEGRO_PI / 2);
    last_update_time = time;
}

void
Track::draw()
{
    Line line = direction.toLine(Vertex(200, 200));
    al_draw_line(line.x, line.y, line.a, line.b, al_map_rgb(100, 100, 100), 10);
    al_draw_prim(&vtx[0], 0, 0, 0, vtx.size(), ALLEGRO_PRIM_LINE_LOOP);
}

// vim:set sw=4 ts=4 et:
