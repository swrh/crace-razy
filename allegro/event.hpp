#if !defined(_ALLEGRO_EVENT_HPP_)
#define _ALLEGRO_EVENT_HPP_

union ALLEGRO_EVENT;

namespace cr {
namespace allegro {

class
event
{
private:
    ALLEGRO_EVENT *data;

public:
    event();
    ~event();

    ALLEGRO_EVENT &get();
};

}
}

#endif // !defined(_ALLEGRO_EVENT_HPP_)

// vim:set sw=4 ts=4 et:
