#if !defined(_SDL_IMG_ERROR_HPP_)
#define _SDL_IMG_ERROR_HPP_

#include "../error.hpp"

namespace sdl {
namespace img {

class
error
: public sdl::exception
{
public:
    error(const std::string &function);
    virtual ~error();
};

}
}

#endif // !defined(_SDL_IMG_ERROR_HPP_)

// vim:set sw=4 ts=4 et tw=120:
