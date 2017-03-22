#if !defined(_ALLEGRO_COLOR_HPP_)
#define _ALLEGRO_COLOR_HPP_

struct ALLEGRO_COLOR;

namespace cr {
namespace allegro {

class
color
{
private:
    color();
    ~color();

public:
    static ALLEGRO_COLOR rgb(unsigned char r, unsigned char g, unsigned char b);
};

}
}

#endif // !defined(_ALLEGRO_COLOR_HPP_)

// vim:set sw=4 ts=4 et:
