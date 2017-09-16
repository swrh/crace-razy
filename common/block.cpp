#include <algorithm>
#include <vector>

#include <lozti/block.hpp>

#include <lozti/algorithm.hpp>

using std::find;
using std::vector;

using lozti::block;

using lozti::flip_lr;
using lozti::transpose;

static vector<block::matrix_type>
rotates(block::matrix_type matrix)
{
    vector<block::matrix_type> matrices;

    unsigned int i = 0;
    for (;;) {
        if (find(matrices.begin(), matrices.end(), matrix) != matrices.end())
            break;

        matrices.push_back(matrix);

        if (++i >= 4)
            break;

        // Rotate CCW.
        flip_lr(matrix);
        transpose(matrix);
    }

    return matrices;
}

block::const_iterator::const_iterator(const block &b)
    : block_(b)
{
}

const block::matrix_type &
block::const_iterator::operator*() const
{
    return block_.at(n);
}

block::const_iterator &
block::const_iterator::operator++()
{
    size_type size = block_.size();

    if (size <= 0 || n >= size)
        n = 0;
    else
        ++n;

    return *this;
}

block::const_iterator &
block::const_iterator::operator--()
{
    size_type size = block_.size();

    if (size <= 0)
        n = 0;
    else if (n <= 0)
        n = size - 1;
    else
        --n;

    return *this;
}

block::block(const matrix_type &matrix)
    : matrices(rotates(matrix))
{
}

block::size_type
block::size() const
{
    return matrices.size();
}

const block::matrix_type &
block::at(size_type n) const
{
    return matrices.at(n);
}

block::const_iterator
block::iterate() const
{
    return const_iterator(*this);
}

// vim:set sw=4 ts=4 et tw=120:
