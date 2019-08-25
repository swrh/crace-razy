#if !defined(_LOZTI_POINT_HPP_)
#define _LOZTI_POINT_HPP_

#include <ostream>

#include <lozti/core/types.hpp>

namespace lozti {

class
point
{
public:
    typedef lozti::size_type size_type;

private:
    size_type x_, y_;

public:
    point();
    point(size_type x, size_type y);

    size_type x() const;
    size_type y() const;

    bool operator==(const point &other) const;
    bool operator!=(const point &other) const;

    point &operator+=(const point &other);
    point &operator-=(const point &other);
    point &operator*=(const point &other);
    point &operator/=(const point &other);

    point operator+(const point &other) const;
    point operator-(const point &other) const;
    point operator*(const point &other) const;
    point operator/(const point &other) const;

public:
    friend std::ostream &operator<<(std::ostream &stream, const point &p);

};

}

#endif // !defined(_LOZTI_POINT_HPP_)

// vim:set sw=4 ts=4 et tw=120:
