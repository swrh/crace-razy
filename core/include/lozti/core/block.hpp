#if !defined(_LOZTI_BLOCK_HPP_)
#define _LOZTI_BLOCK_HPP_

#include <vector>

#include <lozti/core/vector_matrix.hpp>

namespace lozti {

class
block
{
public:
    typedef bool data_type;
    typedef vector_matrix<data_type> matrix_type;
    typedef matrix_type::size_type size_type;

private:
    const std::vector<matrix_type> matrices;

public:
    class
    iterator
    {
    private:
        const block &block_;
        size_type n = 0;

    public:
        iterator(const block &b);

        const matrix_type *operator->() const;
        const matrix_type &operator*() const;
        iterator &operator++();
        iterator &operator--();
    };

public:
    block(const matrix_type &m);

public:
    const matrix_type &operator[](size_type n) const;

    size_type size() const;
    const matrix_type &at(size_type n) const;
    iterator iterate() const;

    friend bool operator<(const block &left, const block &right);
};

}

#endif // !defined(_LOZTI_BLOCK_HPP_)

// vim:set sw=4 ts=4 et tw=120: