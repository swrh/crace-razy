#if !defined(_SDL_HPP_)
#define _SDL_HPP_

#include "sdl/types.hpp"

#include <string>

namespace sdl {

/**
 * @see SDL_CreateWindow
 */
window create_window(const std::string &title, unsigned int width, unsigned int height);

/**
 * @see SDL_CreateRenderer
 */
renderer create_renderer(window &w, int index, uint32_t flags);

/**
 * @see SDL_CreateTextureFromSurface
 */
texture create_texture_from_surface(renderer &r, surface &s);

}

#endif // !defined(_SDL_HPP_)

// vim:set sw=4 ts=4 et tw=120:
