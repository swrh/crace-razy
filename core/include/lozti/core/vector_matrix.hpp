#if !defined(_LOZTI_VECTOR_MATRIX_HPP_)
#define _LOZTI_VECTOR_MATRIX_HPP_

#include <ostream>
#include <stdexcept>
#include <utility>
#include <vector>

#include <lozti/core/point.hpp>
#include <lozti/core/types.hpp>

namespace lozti {

template <typename T> class
vector_matrix
{
public:
    typedef lozti::size_type size_type;
    typedef std::vector<T> container_type;
    typedef typename container_type::value_type value_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;

private:
    container_type data_;
    size_type width_, height_;

public:
    vector_matrix()
        : width_(0), height_(0)
    {
    }

    vector_matrix(size_type w, size_type h)
        : data_(w * h), width_(w), height_(h)
    {
    }

    vector_matrix(size_type w, size_type h, const container_type &d)
        : data_(d), width_(w), height_(h)
    {
        if (data_.size() != (width_ * height_))
            throw std::runtime_error("invalid width/height");
    }

    vector_matrix(size_type w, size_type h, container_type &&d)
        : data_(d), width_(w), height_(h)
    {
        if (data_.size() != (width_ * height_))
            throw std::runtime_error("invalid width/height");
    }

    vector_matrix(const vector_matrix &other)
        : data_(other.data_), width_(other.width_), height_(other.height_)
    {
    }

    vector_matrix(vector_matrix &&other)
        : data_(other.data_), width_(other.width_), height_(other.height_)
    {
        other.width_ = 0;
        other.height_ = 0;
    }

public:
    vector_matrix &
    operator=(const vector_matrix &other)
    {
        if (this == &other)
            return *this;
        data_ = other.data_;
        width_ = other.width_;
        height_ = other.height_;
        return *this;
    }

    vector_matrix &
    operator=(vector_matrix &&other)
    {
        if (this == &other)
            return *this;
        swap(other);
        return *this;
    }

    bool
    operator==(const vector_matrix &other) const
    {
        return (width_ == other.width_) &&
            (height_ == other.height_) &&
            (data_ == other.data_);
    }

    value_type &
    operator[](size_type i)
    {
        return data_[i];
    }

    const_iterator
    begin() const
    {
        return data_.begin();
    }

    iterator
    begin()
    {
        return data_.begin();
    }

    const_iterator
    end() const
    {
        return data_.end();
    }

    iterator
    end()
    {
        return data_.end();
    }

    size_type
    size() const
    {
        return data_.size();
    }

    size_type
    width() const
    {
        return width_;
    }

    size_type
    height() const
    {
        return height_;
    }

public:
    const value_type &
    operator()(size_type x, size_type y) const
    {
        return data_[width_ * y + x];
    }

    value_type &
    operator()(size_type x, size_type y)
    {
        return data_[width_ * y + x];
    }

    const value_type &
    at(size_type x, size_type y) const
    {
        return data_.at(width_ * y + x);
    }

    value_type &
    at(size_type x, size_type y)
    {
        return data_.at(width_ * y + x);
    }

public:
    value_type
    value(const point &p) const
    {
        return data_[width_ * p.y() + p.x()];
    }

public:
    void
    resize(size_type w, size_type h)
    {
        data_.resize(w * h);
        width_ = w;
        height_ = h;
    }

public:
    void
    swap(vector_matrix &other)
    {
        using std::swap;
        data_.swap(other.data_);
        swap(width_, other.width_);
        swap(height_, other.height_);
    }

public:
    friend bool
    operator<(const vector_matrix &left, const vector_matrix &right)
    {
        const auto &ld = left.data_;
        const auto &rd = right.data_;

        if (ld.size() < rd.size())
            return true;

        for (auto l = ld.begin(), r = rd.begin(); l != ld.end() && r != rd.end(); ++l, ++r) {
            if (*l < *r)
                return true;
        }

        return false;
    }

    friend std::ostream &
    operator<<(std::ostream &out, const vector_matrix &m)
    {
        out << "(";
        for (size_type y = 0; y < m.height(); ++y) {
            if (y != 0)
                out << ", ";
            out << "(";
            for (size_type x = 0; x < m.width(); ++x) {
                if (x != 0)
                    out << ", ";
                out << m.data_[y * m.width() + x];
            }
            out << ")";
        }
        out << ")";
        return out;
    }
};

template <typename T> vector_matrix<T>
make_vector_matrix(typename vector_matrix<T>::size_type w, typename vector_matrix<T>::size_type h)
{
    return vector_matrix<T>(w, h);
}

}

#endif // !defined(_LOZTI_VECTOR_MATRIX_HPP_)

// vim:set sw=4 ts=4 et tw=120:
