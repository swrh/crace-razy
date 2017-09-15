#if !defined(_LOZTI_VECTOR_MATRIX_HPP_)
#define _LOZTI_VECTOR_MATRIX_HPP_

#include <stdexcept>
#include <utility>
#include <vector>

namespace lozti {

template <typename T> class
vector_matrix
{
public:
    typedef std::size_t size_type;
    typedef T value_type;
    typedef std::vector<value_type> container_type;
    typedef typename container_type::iterator iterator;

private:
    container_type data_;
    size_type width_, height_;

public:
    vector_matrix(size_type w, size_type h)
        : data_(w * h), width_(w), height_(h)
    {
        if (data_.size() == 0)
            throw std::logic_error("invalid width/height");
    }

    vector_matrix(const vector_matrix<T> &other)
        : data_(other.data_), width_(other.width_), height_(other.height_)
    {
    }

    vector_matrix(vector_matrix<T> &&other)
        : data_(other.data_), width_(other.width_), height_(other.height_)
    {
        other.width_ = 0;
        other.height_ = 0;
    }

public:
    vector_matrix<T> &
    operator=(const vector_matrix<T> &other)
    {
        if (this == &other)
            return *this;
        data_ = other.data_;
        width_ = other.width_;
        height_ = other.height_;
        return *this;
    }

    vector_matrix<T> &
    operator=(vector_matrix<T> &&other)
    {
        if (this == &other)
            return *this;
        std::swap(*this, other);
        return *this;
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
    void
    resize(size_type w, size_type h)
    {
        data_.resize(w * h);
        width_ = w;
        height_ = h;
    }

public:
    friend void
    swap(vector_matrix<T> &left, vector_matrix<T> &right)
    {
        std::swap(left.data_, right.data_);
        std::swap(left.width_, right.width_);
        std::swap(left.height_, right.height_);
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
