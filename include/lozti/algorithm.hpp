#if !defined(_LOZTI_ALGORITHM_HPP_)
#define _LOZTI_ALGORITHM_HPP_

#include <algorithm>
#include <utility>
#include <vector>

namespace lozti {

template <typename T> void
flip_lr(T &matrix)
{
    const typename T::size_type width = matrix.width();
    const typename T::size_type height = matrix.height();
    for (typename T::size_type y = 0; y < height; ++y)
        std::reverse(&matrix[y * width], &matrix[(y + 1) * width]);
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
    std::vector<bool> visited(size);
    for (typename T::size_type i = 1; i < size; ++i) {
        if (visited[i])
            continue;
        typename T::size_type j = i;
        for (;;) {
            if (j != (size - 1))
                j = (matrix.height() * j) % (size - 1);
            if (j == i)
                break;
            std::swap(matrix[j], matrix[i]);
            visited[j] = true;
        }
    }
    matrix.resize(matrix.height(), matrix.width());
}

}

#endif // !defined(_LOZTI_ALGORITHM_HPP_)

// vim:set sw=4 ts=4 et tw=120:
