#include <lozti/core/point.hpp>

using lozti::point;

namespace lozti {

point::point()
    : point(0, 0)
{
}

point::point(size_type x, size_type y)
    : x_(x), y_(y)
{
}

point::size_type
point::x() const
{
    return x_;
}

point::size_type
point::y() const
{
    return y_;
}

bool
point::operator==(const point &other) const
{
    return x_ == other.x_ && y_ == other.y_;
}

bool
point::operator!=(const point &other) const
{
    return !this->operator==(other);
}

point &
point::operator+=(const point &other)
{
    x_ += other.x_;
    y_ += other.y_;

    return *this;
}

point &
point::operator-=(const point &other)
{
    x_ -= other.x_;
    y_ -= other.y_;

    return *this;
}

point &
point::operator*=(const point &other)
{
    x_ *= other.x_;
    y_ *= other.y_;

    return *this;
}

point &
point::operator/=(const point &other)
{
    x_ /= other.x_;
    y_ /= other.y_;

    return *this;
}

point
point::operator+(const point &other) const
{
    point p(*this);

    p += other;

    return p;
}

point
point::operator-(const point &other) const
{
    point p(*this);

    p -= other;

    return p;
}

point
point::operator*(const point &other) const
{
    point p(*this);

    p *= other;

    return p;
}

point
point::operator/(const point &other) const
{
    point p(*this);

    p /= other;

    return p;
}

std::ostream &
operator<<(std::ostream &stream, const point &p)
{
    return stream << p.x_ << ',' << p.y_;
}

}

// vim:set sw=4 ts=4 et tw=120:
