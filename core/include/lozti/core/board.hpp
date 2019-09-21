#if !defined(_LOZTI_BOARD_HPP_)
#define _LOZTI_BOARD_HPP_

#include <cstddef>
#include <memory>

#include <lozti/core/block.hpp>
#include <lozti/core/point.hpp>
#include <lozti/core/types.hpp>
#include <lozti/core/vector_matrix.hpp>

namespace lozti {

class
board
{
public:
    typedef lozti::size_type size_type;
    typedef lozti::vector_matrix<bool> matrix_type;
    typedef typename matrix_type::value_type value_type;

public:
    class movable_block
    {
    private:
        board &board_;
        block block_;
        point position_;

    public:
        movable_block(board &brd, const block &blk);

        point position() const;
        const block::matrix_type &matrix() const;

        bool move(const point &new_position);
        bool step(const point &step);

    public:
        bool move_left();
        bool move_right();
        bool move_top();
        bool move_bottom();

        bool step_left();
        bool step_right();
        bool step_up();
        bool step_down();

        bool center_horizontally();
        bool center_vertically();

        bool rotate_clockwise();
        bool rotate_counterclockwise();

        bool drop();

    };

private:
    matrix_type matrix_;
    std::shared_ptr<movable_block> movable_block_;

public:
    board(size_type w, size_type h);

    const matrix_type &matrix() const;

    size_type width() const;
    size_type height() const;

    bool colides_with(const matrix_type &m, const point &position);

public:
    movable_block &push(const block &blk);

};

}

#endif // !defined(_LOZTI_BOARD_HPP_)

// vim:set sw=4 ts=4 et tw=120:
