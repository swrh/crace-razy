#include <algorithm>

#include <lozti/core/block.hpp>

#include <lozti/core/algorithm.hpp>

using lozti::block;

namespace lozti {

block::block(const block_data &data)
    : data_(data)
{
}

const block_data::matrix_type &
block::matrix() const
{
    return data_[n];
}

void
block::rotate_clockwise()
{
    size_type size = data_.size();

    if (size <= 0 || n >= (size - 1))
        n = 0;
    else
        ++n;
}

void
block::rotate_counterclockwise()
{
    size_type size = data_.size();

    if (size <= 0)
        n = 0;
    else if (n <= 0)
        n = size - 1;
    else
        --n;
}

}

// vim:set sw=4 ts=4 et tw=120:
