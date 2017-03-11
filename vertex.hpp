#if !defined(_VERTEX_HPP_)
#define _VERTEX_HPP_

struct
Vertex
{
    float x, y;

    Vertex();
    Vertex(float x, float y);

    void set(float x, float y);
    void move(float x, float y);
    void move(const Vertex &p);
};

#endif // !defined(_VERTEX_HPP_)

// vim:set sw=4 ts=4 et:
