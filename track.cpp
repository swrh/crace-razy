#include "track.hpp"

#include <allegro5/allegro_primitives.h>

#include <math.h>

Track::Track()
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
}

void
Track::draw()
{
    al_draw_line(5, 5, 200, 200, al_map_rgb(120, 120, 120), 1);
    al_draw_prim(&vtx[0], 0, 0, 0, vtx.size(), ALLEGRO_PRIM_LINE_LOOP);
}

// vim:set sw=4 ts=4 et:
