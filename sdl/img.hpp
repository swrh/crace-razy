#if !defined(_SDL_IMG_HPP_)
#define _SDL_IMG_HPP_

#include "types.hpp"

#include <string>

namespace sdl {
namespace img {

/**
 * @see IMG_Load
 */
surface load(const std::string &filename);

}
}

#endif // !defined(_SDL_IMG_HPP_)

// vim:set sw=4 ts=4 et tw=120:
