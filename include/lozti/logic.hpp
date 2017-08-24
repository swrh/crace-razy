#if !defined(_LOZTI_LOGIC_HPP_)
#define _LOZTI_LOGIC_HPP_

#include <list>
#include <utility>
#include <vector>

#include <boost/optional.hpp>

#include <lozti/piece.hpp>

namespace lozti {

class
logic
{
public:
    enum class
    direction
    {
        left,
        right,
    };

    typedef piece::data_type data_type;
    typedef std::vector<data_type> line_type;
    typedef std::vector<line_type> matrix_type;
    typedef matrix_type::size_type size_type;

    size_type
    width() const
    {
        return board_.at(0).size();
    }

    size_type
    height() const
    {
        return board_.size();
    }

private:
    matrix_type board_;

    boost::optional<piece> current_piece_;
    std::pair<size_type, size_type> current_position_;

public:
    logic(size_type width, size_type height)
        : board_(height, line_type(width, 0))
    {
    }

    ~logic()
    {
    }

    void
    step()
    {
        if (!current_piece_) {
            current_piece_ = piece::create_random();
            current_position_ = std::make_pair(width() / 2, height() - 1);
            return;
        }

        current_piece_.reset();
    }

    void
    rotate()
    {
        if (!current_piece_)
            return;

        for (int i = 0; i < 3; i++) {
            current_piece_->rotate();
            if (!collides())
                return;
        }

        // Could not rotate, go back to the original position.
        current_piece_->rotate();
    }

    bool
    collides()
    {
        if (!current_piece_)
            return false;

        return true;
    }

    void
    move(direction d)
    {
        size_type &x = current_position_.first;
        int movement = 0;

        switch (d) {
        case direction::left:
            if (x > 0)
                movement = -1;
            break;

        case direction::right:
            if (x < (width() - 1))
                movement = 1;
            break;
        }

        if (!movement)
            return;

        x += movement;
        if (collides())
            x -= movement;
    }

    void
    drop()
    {
    }

};

}

#endif // !defined(_LOZTI_LOGIC_HPP_)

// vim:set sw=4 ts=4 et tw=120:
