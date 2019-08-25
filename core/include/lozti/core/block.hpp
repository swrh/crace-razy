#if !defined(_LOZTI_BLOCK_HPP_)
#define _LOZTI_BLOCK_HPP_

#include <lozti/core/block_data.hpp>

namespace lozti {

class
block
{
public:
    typedef block_data::matrix_type matrix_type;

private:
    const block_data &data_;
    size_type n = 0;

public:
    block(const block_data &b);

    void rotate_clockwise();
    void rotate_counterclockwise();

    const matrix_type &matrix() const;
};

}

#endif // !defined(_LOZTI_BLOCK_HPP_)

// vim:set sw=4 ts=4 et tw=120:
