#if !defined(_ALLEGRO_LINE_HPP_)
#define _ALLEGRO_LINE_HPP_

#include "color.hpp"
#include "polygon.hpp"
#include "vector.hpp"
#include "vertex.hpp"

namespace cr {
namespace allegro {

class
line
: public polygon
{
public:
    line(const vertex &base, const vector &vect);

    void draw(const allegro::color::allegro_color &color, float thickness) const;
};

}
}

#endif // !defined(_ALLEGRO_LINE_HPP_)

// vim:set sw=4 ts=4 et:
