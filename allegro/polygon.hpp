#if !defined(_ALLEGRO_POLYGON_HPP_)
#define _ALLEGRO_POLYGON_HPP_

#include <vector>

struct ALLEGRO_VERTEX;

namespace cr {
namespace allegro {

class
polygon
{
public:
    typedef std::size_t size_type;
    typedef ALLEGRO_VERTEX vertex;

private:
    std::vector<vertex> data;

public:
    polygon();
    polygon(size_type count);
    ~polygon();

    size_type size() const;
    vertex &at(size_type pos);

    vertex &operator[](size_type pos);
};

}
}

#endif // !defined(_ALLEGRO_POLYGON_HPP_)

// vim:set sw=4 ts=4 et:
