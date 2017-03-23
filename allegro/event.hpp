#if !defined(_ALLEGRO_EVENT_HPP_)
#define _ALLEGRO_EVENT_HPP_

union ALLEGRO_EVENT;

namespace cr {
namespace allegro {

class
event
{
public:
    typedef ALLEGRO_EVENT allegro_event;

private:
    allegro_event *data;

public:
    event();
    ~event();

    allegro_event &get();
};

}
}

#endif // !defined(_ALLEGRO_EVENT_HPP_)

// vim:set sw=4 ts=4 et:
