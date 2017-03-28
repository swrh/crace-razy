#include "exception.hpp"

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

// vim:set sw=4 ts=4 et tw=120:
