#if !defined(_LOZTI_ARRAY_MATRIX_HPP_)
#define _LOZTI_ARRAY_MATRIX_HPP_

#include <array>
#include <stdexcept>
#include <utility>
#include <vector>

namespace lozti {

template <typename T, std::size_t S> class
array_matrix
{
public:
    typedef std::size_t size_type;
    typedef T value_type;
    typedef std::array<value_type, S> container_type;

private:
    size_type width_, height_;

    container_type data_;

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

public:
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
    transpose()
    {
        std::vector<bool> visited(data_.size());
        for (typename container_type::iterator it = data_.begin() + 1; it != data_.end(); ++it) {
            size_type i = it - data_.begin();
            if (visited[i])
                continue;
            do  {
                if (i != (data_.size() - 1))
                    i = (height_ * i) % (data_.size() - 1);
                std::swap(*(data_.begin() + i), *it);
                visited[i] = true;
            } while ((data_.begin() + i) != it);
        }
        std::swap(width_, height_);
    }

    bool
    resize(size_type w, size_type h)
    {
        if ((w * h) != data_.size())
            return false;

        width_ = w;
        height_ = h;
        return true;
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
