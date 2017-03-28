#if !defined(_SDL_TYPES_HPP_)
#define _SDL_TYPES_HPP_

#include <SDL.h>

#include <memory>

namespace sdl {

typedef std::shared_ptr<SDL_Renderer> renderer;
typedef std::shared_ptr<SDL_Surface> surface;
typedef std::shared_ptr<SDL_Texture> texture;
typedef std::shared_ptr<SDL_Window> window;

}

#endif // !defined(_SDL_TYPES_HPP_)

// vim:set sw=4 ts=4 et tw=120:
