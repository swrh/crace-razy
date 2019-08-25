#if !defined(_LOZTI_ARRAY_MATRIX_HPP_)
#define _LOZTI_ARRAY_MATRIX_HPP_

#include <array>
#include <functional>
#include <stdexcept>
#include <utility>

namespace lozti {

template <typename T, std::size_t S> class
array_matrix
{
public:
    typedef std::size_t size_type;
    typedef T value_type;
    typedef std::array<value_type, S> container_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;

private:
    container_type data_;
    size_type width_, height_;

public:
    array_matrix(size_type w = 1)
        : width_(w)
    {
        if (data_.size() == 0)
            throw std::logic_error("invalid size");

        if (width_ <= 0 || (data_.size() % width_) != 0)
            throw std::logic_error("invalid width");

        height_ = data_.size() / width_;
    }

    array_matrix(const array_matrix<T, S> &other)
        : data_(other.data_), width_(other.width_), height_(other.height_)
    {
    }

    array_matrix(array_matrix<T, S> &&other)
        : data_(other.data_), width_(std::ref(other.width_)), height_(std::ref(other.height_))
    {
    }

public:
    array_matrix<T, S> &
    operator=(const array_matrix<T, S> &other)
    {
        if (this == &other)
            return *this;
        data_ = other.data_;
        width_ = other.width_;
        height_ = other.height_;
        return *this;
    }

    bool
    operator==(const array_matrix<T, S> &other)
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

    iterator
    begin()
    {
        return data_.begin();
    }

    const_iterator
    cbegin() const
    {
        return data_.begin();
    }

    iterator
    end()
    {
        return data_.end();
    }

    const_iterator
    cend() const
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
    void
    resize(size_type w, size_type h)
    {
        if ((w * h) != data_.size())
            throw std::logic_error("invalid size");
        width_ = w;
        height_ = h;
    }

public:
    void
    swap(array_matrix<T, S> &other)
    {
        using std::swap;
        data_.swap(other.data_);
        swap(width_, other.width_);
        swap(height_, other.height_);
    }
};

template <typename T, std::size_t W, std::size_t H> array_matrix<T, W * H>
make_array_matrix()
{
    return array_matrix<T, W * H>(W);
}

}

#endif // !defined(_LOZTI_ARRAY_MATRIX_HPP_)

// vim:set sw=4 ts=4 et tw=120:
