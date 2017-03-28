#if !defined(_SDL_ERROR_HPP_)
#define _SDL_ERROR_HPP_

#include "exception.hpp"

namespace sdl {

class
error
: public exception
{
public:
    error(const std::string &function);
    virtual ~error();
};

}

#endif // !defined(_SDL_ERROR_HPP_)

// vim:set sw=4 ts=4 et tw=120:
