#include "sdl.hpp"

#include "sdl/error.hpp"
#include "sdl/types.hpp"

#include <SDL.h>

using namespace sdl;

window
sdl::create_window(const std::string &title, unsigned int width, unsigned int height)
{
    window w(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                width, height, SDL_WINDOW_SHOWN), SDL_DestroyWindow);
    if (w == nullptr)
        throw error("SDL_CreateWindow");
    return w;
}

renderer
sdl::create_renderer(window &w, int index, uint32_t flags)
{
    renderer r(SDL_CreateRenderer(w.get(), index, flags), SDL_DestroyRenderer);
    if (r == nullptr)
        throw error("SDL_CreateRenderer");
    return r;
}

texture
sdl::create_texture_from_surface(renderer &r, surface &s)
{
    texture t(SDL_CreateTextureFromSurface(r.get(), s.get()), SDL_DestroyTexture);
    if (t == nullptr)
        throw error("SDL_CreateTextureFromSurface");
    return t;
}

// vim:set sw=4 ts=4 et tw=120:
