#if !defined(_LOZTI_VECTOR_MATRIX_HPP_)
#define _LOZTI_VECTOR_MATRIX_HPP_

#include <vector>
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

public:
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

};

template <typename T> vector_matrix<T>
make_vector_matrix(typename vector_matrix<T>::size_type w, typename vector_matrix<T>::size_type h)
{
    return vector_matrix<T>(w, h);
}

}

#endif // !defined(_LOZTI_VECTOR_MATRIX_HPP_)

// vim:set sw=4 ts=4 et tw=120:
