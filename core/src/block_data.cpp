#include <algorithm>
#include <vector>

#include <lozti/core/block_data.hpp>

#include <lozti/core/algorithm.hpp>

using std::find;
using std::vector;

using lozti::block_data;

namespace lozti {

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

block_data::block_data(const matrix_type &matrix)
    : matrices(rotates<vector>(matrix))
{
}

const block_data::matrix_type &
block_data::operator[](size_type n) const
{
    return matrices[n];
}

block_data::size_type
block_data::size() const
{
    return matrices.size();
}

const block_data::matrix_type &
block_data::at(size_type n) const
{
    return matrices.at(n);
}

bool
operator<(const block_data &left, const block_data &right)
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
