#include <memory>

#include <lozti/core/board.hpp>

using lozti::board;

namespace lozti {

board::board(size_type w, size_type h)
    : matrix_(w, h)
{
}

const board::matrix_type &
board::matrix() const
{
    return matrix_;
}

size_type
board::width() const
{
    return matrix_.width();
}

size_type
board::height() const
{
    return matrix_.height();
}

bool
board::colides_with(const matrix_type &m, const point &position)
{
    if (position.x() < 0 || position.y() < 0)
        return true;

    if ((position.x() + m.width()) > matrix_.width() || (position.y() + m.height()) > matrix_.height())
        return true;

    for (matrix_type::size_type y = 0; y < m.height(); ++y) {
        for (matrix_type::size_type x = 0; x < m.width(); ++x) {
            point p(x, y);
            if (matrix_.value(position + p) && m.value(p))
                return true;
        }
    }

    return false;
}

board::movable_block &
board::push(const block &blk)
{
    movable_block_ = std::make_shared<movable_block>(std::ref(*this), std::ref(blk));

    return *movable_block_;
}

board::movable_block::movable_block(board &brd, const block &blk)
    : board_(brd), block_(blk)
{
}

point
board::movable_block::position() const
{
    return position_;
}

const block::matrix_type &
board::movable_block::matrix() const
{
    return block_.matrix();
}

bool
board::movable_block::move(const point &new_position)
{
    if (board_.colides_with(block_.matrix(), new_position))
        return false;
    position_ = new_position;
    return true;
}

bool
board::movable_block::step(const point &step)
{
    return move(position_ + step);
}

bool
board::movable_block::move_left()
{
    return move(position_ * point(0, 1));
}

bool
board::movable_block::move_right()
{
    return move(point(board_.width() - block_.matrix().width(), position_.y()));
}

bool
board::movable_block::move_top()
{
    return move(position_ * point(1, 0));
}

bool
board::movable_block::move_bottom()
{
    return move(point(position_.x(), board_.height() - block_.matrix().height()));
}

bool
board::movable_block::step_left()
{
    return step(point(-1, 0));
}

bool
board::movable_block::step_right()
{
    return step(point(1, 0));
}

bool
board::movable_block::step_up()
{
    return step(point(0, -1));
}

bool
board::movable_block::step_down()
{
    return step(point(0, 1));
}

bool
board::movable_block::center_horizontally()
{
    return move(point((board_.width() - block_.matrix().width()) / 2, position_.y()));
}

bool
board::movable_block::center_vertically()
{
    return move(point(position_.x(), (board_.height() - block_.matrix().height()) / 2));
}

bool
board::movable_block::rotate_clockwise()
{
    block b(block_);
    b.rotate_clockwise();
    if (board_.colides_with(b.matrix(), position_))
        return false;
    block_.rotate_clockwise();
    return true;
}

bool
board::movable_block::rotate_counterclockwise()
{
    block b(block_);
    b.rotate_counterclockwise();
    if (board_.colides_with(b.matrix(), position_))
        return false;
    block_.rotate_counterclockwise();
    return true;
}

bool
board::movable_block::drop()
{
    point new_position(position_.x(), board_.height() - block_.matrix().height());

    while (new_position.y() > 0 && new_position != position_) {
        if (move(new_position))
            return true;

        new_position -= point(0, 1);
    }

    return false;
}

}

// vim:set sw=4 ts=4 et tw=120:
