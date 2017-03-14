#if !defined(_LINE_HPP_)
#define _LINE_HPP_

namespace cr {

struct
line
{
    float x, y, a, b;

    line(float x, float y, float a, float b);
};

}

#endif // !defined(_LINE_HPP_)

// vim:set sw=4 ts=4 et:
