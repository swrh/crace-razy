#if !defined(_LOZTI_BOARD_HPP_)
#define _LOZTI_BOARD_HPP_

#include <cstddef>

#include <lozti/core/types.hpp>
#include <lozti/core/vector_matrix.hpp>

namespace lozti {

class
board
{
public:
    typedef lozti::size_type size_type;
    typedef bool value_type;
    typedef lozti::vector_matrix<value_type> container_type;

private:
    container_type data_;

public:
    board(size_type w, size_type h);

    const container_type &get_data() const;
};

}

#endif // !defined(_LOZTI_BOARD_HPP_)

// vim:set sw=4 ts=4 et tw=120:
