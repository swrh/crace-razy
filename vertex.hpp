#if !defined(_VERTEX_HPP_)
#define _VERTEX_HPP_

namespace cr {

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

#endif // !defined(_VERTEX_HPP_)

// vim:set sw=4 ts=4 et:
