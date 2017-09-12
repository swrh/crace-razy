#if !defined(_LOZTI_ALGORITHM_HPP_)
#define _LOZTI_ALGORITHM_HPP_

#include <utility>
#include <vector>

namespace lozti {

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
