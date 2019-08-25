#include <lozti/core/board.hpp>

using lozti::board;

namespace lozti {

board::board(size_type w, size_type h)
    : data_(w, h)
{
}

const board::container_type &
board::get_data() const
{
    return data_;
}

}

// vim:set sw=4 ts=4 et tw=120:
