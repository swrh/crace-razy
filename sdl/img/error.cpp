#include "error.hpp"

#include <SDL_image.h>

using namespace sdl::img;

sdl::img::error::error(const std::string &function)
    : sdl::exception(function + ": " + IMG_GetError())
{
}

sdl::img::error::~error()
{
}

// vim:set sw=4 ts=4 et tw=120:
