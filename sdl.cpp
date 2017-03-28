#include "sdl.hpp"

#include <SDL.h>
#include <SDL_image.h>

using namespace sdl;

sdl::exception::exception(const std::string &message)
    : message(message)
{
}

sdl::exception::~exception()
{
}

const char *
sdl::exception::what() const throw()
{
    return message.c_str();
}

window
sdl::create_window(const std::string &title, unsigned int width, unsigned int height)
{
    window w(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                width, height, SDL_WINDOW_SHOWN), SDL_DestroyWindow);
    if (w == nullptr)
        throw exception(SDL_GetError());
    return w;
}

renderer
sdl::create_renderer(window &w, int index, uint32_t flags)
{
    renderer r(SDL_CreateRenderer(w.get(), index, flags), SDL_DestroyRenderer);
    if (r == nullptr)
        throw exception(SDL_GetError());
    return r;
}

texture
sdl::create_texture_from_surface(renderer &r, surface &s)
{
    texture t(SDL_CreateTextureFromSurface(r.get(), s.get()), SDL_DestroyTexture);
    if (t == nullptr)
        throw exception(SDL_GetError());
    return t;
}

surface
sdl::img::load(const std::string &filename)
{
    surface s(IMG_Load(filename.c_str()), SDL_FreeSurface);
    if (s == nullptr)
        throw exception(IMG_GetError());
    return s;
}

// vim:set sw=4 ts=4 et tw=120:
