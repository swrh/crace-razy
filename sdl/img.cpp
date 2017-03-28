#include "img.hpp"

#include "img/error.hpp"

#include <SDL_image.h>

using namespace sdl::img;

sdl::surface
sdl::img::load(const std::string &filename)
{
    surface s(IMG_Load(filename.c_str()), SDL_FreeSurface);
    if (s == nullptr)
        throw error("IMG_Load");
    return s;
}

// vim:set sw=4 ts=4 et tw=120:
