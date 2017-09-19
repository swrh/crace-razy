#include <algorithm>
#include <vector>

#include <lozti/block.hpp>

#include <lozti/algorithm.hpp>

using std::find;
using std::vector;

using lozti::block;

using lozti::flip_lr;
using lozti::transpose;

/**
 * Rotate the input matrix and return all possible positions in a container.
 */
template <template <class ...> class V, class T> static V<T>
rotates(T matrix)
{
    V<T> ret;

    unsigned int n = 0;
    for (;;) {
        if (find(ret.begin(), ret.end(), matrix) != ret.end())
            break;

        ret.push_back(matrix);

        if (++n >= 4)
            break;

        // Rotate CCW.
        flip_lr(matrix);
        transpose(matrix);
    }

    return ret;
}

block::iterator::iterator(const block &b)
    : block_(b)
{
}

const block::matrix_type *
block::iterator::operator->() const
{
    return &block_[n];
}

const block::matrix_type &
block::iterator::operator*() const
{
    return block_[n];
}

block::iterator &
block::iterator::operator++()
{
    size_type size = block_.size();

    if (size <= 0 || n >= (size - 1))
        n = 0;
    else
        ++n;

    return *this;
}

block::iterator &
block::iterator::operator--()
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
    : matrices(rotates<vector>(matrix))
{
}

const block::matrix_type &
block::operator[](size_type n) const
{
    return matrices[n];
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

block::iterator
block::iterate() const
{
    return iterator(*this);
}

namespace lozti {

bool
operator<(const block &left, const block &right)
{
    const auto &lm = left.matrices;
    const auto &rm = right.matrices;

    if (lm.size() < rm.size())
        return true;

    for (auto l = lm.cbegin(), r = rm.cbegin(); l != lm.end() && r != rm.end(); ++l, ++r) {
        if (l->size() < r->size())
            return true;
    }

    for (auto l = lm.cbegin(), r = rm.cbegin(); l != lm.end() && r != rm.end(); ++l, ++r) {
        if (*l < *r)
            return true;
    }

    return false;
}

}

// vim:set sw=4 ts=4 et tw=120:
