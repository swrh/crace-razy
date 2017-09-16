#if !defined(_LOZTI_ALGORITHM_HPP_)
#define _LOZTI_ALGORITHM_HPP_

#include <algorithm>
#include <utility>
#include <vector>

namespace lozti {

template <class Distance, class InputIt> constexpr void
advances(Distance n, InputIt &it)
{
    std::advance(it, n);
}

template <class Distance, class InputIt, class ...InputIts> constexpr void
advances(Distance n, InputIt &it, InputIts &...its)
{
    advances(n, it);
    advances(n, its...);
}

template <typename T> void
flip_lr(T &matrix)
{
    const typename T::size_type width = matrix.width();
    for (auto cur = matrix.begin(), next = cur + width; cur != matrix.end(); advances(width, cur, next))
        std::reverse(cur, next);
}

template <typename T> void
flip_ud(T &matrix)
{
    const typename T::size_type width = matrix.width();
    const typename T::size_type height = matrix.height();
    for (typename T::size_type x = 0; x < width; ++x)
        for (typename T::size_type y = 0; y < (height / 2); ++y)
            std::swap(matrix(x, y), matrix(x, height - y - 1));
}

template <typename T> void
transpose(T &matrix)
{
    const typename T::size_type size = matrix.size();
    const typename T::size_type height = matrix.height();
    std::vector<bool> visited(size);
    for (typename T::size_type i = 1; i < size; ++i) {
        if (visited[i])
            continue;
        typename T::size_type j = i;
        for (;;) {
            if (j != (size - 1))
                j = (height * j) % (size - 1);
            if (j == i)
                break;
            // Can't use swap(T::operator[]) if T is a bitset (vector<bool>), so... use random access iterators.
            std::iter_swap(matrix.begin() + j, matrix.begin() + i);
            visited[j] = true;
        }
    }
    matrix.resize(height, matrix.width());
}

}

#endif // !defined(_LOZTI_ALGORITHM_HPP_)

// vim:set sw=4 ts=4 et tw=120:
