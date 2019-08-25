#if !defined(_LOZTI_BLOCK_DATA_HPP_)
#define _LOZTI_BLOCK_DATA_HPP_

#include <vector>

#include <lozti/core/vector_matrix.hpp>

namespace lozti {

class
block_data
{
public:
    typedef bool data_type;
    typedef vector_matrix<data_type> matrix_type;
    typedef matrix_type::size_type size_type;

private:
    const std::vector<matrix_type> matrices;

public:
    block_data(const matrix_type &m);

public:
    const matrix_type &operator[](size_type n) const;

    size_type size() const;
    const matrix_type &at(size_type n) const;

    friend bool operator<(const block_data &left, const block_data &right);
};

}

#endif // !defined(_LOZTI_BLOCK_DATA_HPP_)

// vim:set sw=4 ts=4 et tw=120:
