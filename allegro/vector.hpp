#if !defined(_ALLEGRO_VECTOR_HPP_)
#define _ALLEGRO_VECTOR_HPP_

#include "vertex.hpp"

namespace cr {
namespace allegro {

struct
vector
{
    float theta, a;

    vector();
    vector(float theta, float a);

    void set(float theta);
    void set(float theta, float a);
    void rotate(float r);
};

}
}

#endif // !defined(_ALLEGRO_VECTOR_HPP_)

// vim:set sw=4 ts=4 et:
