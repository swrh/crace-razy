#include "error.hpp"

#include <SDL.h>

using namespace sdl;

sdl::error::error(const std::string &function)
    : exception(function + ": " + SDL_GetError())
{
}

sdl::error::~error()
{
}

// vim:set sw=4 ts=4 et tw=120:
