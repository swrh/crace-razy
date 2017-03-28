#include "exception.hpp"

exception::exception(const std::string &message)
    : message(message)
{
}

exception::~exception()
{
}

const char *
exception::what() const throw()
{
    return message.c_str();
}

// vim:set sw=4 ts=4 et tw=120:
