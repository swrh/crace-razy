#if !defined(_ALLEGRO_VERTEX_HPP_)
#define _ALLEGRO_VERTEX_HPP_

namespace cr {
namespace allegro {

struct
vertex
{
    float x, y;

    vertex();
    vertex(float x, float y);

    void set(float x, float y);
    void move(float x, float y);
    void move(const vertex &p);
};

}
}

#endif // !defined(_ALLEGRO_VERTEX_HPP_)

// vim:set sw=4 ts=4 et:
