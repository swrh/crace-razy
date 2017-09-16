#if !defined(_EXCEPTION_HPP_)
#define _EXCEPTION_HPP_

#include <stdexcept>

class
exception
: public std::exception
{
protected:
    const std::string message;

public:
    exception(const std::string &message);
    virtual ~exception() throw();

    virtual const char *what() const throw();
};

#endif // !defined(_EXCEPTION_HPP_)

// vim:set sw=4 ts=4 et tw=120:
