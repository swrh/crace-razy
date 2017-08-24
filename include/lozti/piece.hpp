#if !defined(_LOZTI_PIECE_HPP_)
#define _LOZTI_PIECE_HPP_

#include <algorithm>

namespace lozti {

class
piece
{
public:
    constexpr static std::size_t
    size()
    {
        return 5;
    }

    typedef char square_type;
    typedef std::array<square_type, 5> line_type;
    typedef std::array<line_type, 5> matrix_type;

private:
    matrix_type board_;

    piece(matrix_type &&b, bool symetric = false)
        : board_(b), symetric_(symetric)
    {
    }

private:
    bool symetric_;

public:
    void
    rotate()
    {
        if (symetric_)
            return;

        for (std::size_t y = 0; y < (size() / 2); y++) {
            for (std::size_t x = y; x < (size() - y - 1); x++) {
                square_type t = board_[y][x];

                std::swap(t, board_[x][size() - y - 1]);
                std::swap(t, board_[size() - y - 1][size() - x - 1]);
                std::swap(t, board_[size() - x - 1][y]);
                std::swap(t, board_[y][x]);
            }
        }
    }

    void
    mirror()
    {
        if (symetric_)
            return;

        for (std::size_t y = 0; y < size(); y++) {
            for (std::size_t x = 0; x < (size() / 2); x++) {
                std::swap(board_[y][x], board_[y][size() - x - 1]);
            }
        }
    }

public:
    const matrix_type &
    board() const
    {
        return board_;
    }

public:
    static piece
    create_l()
    {
        static piece p({{
                { 0, 0, 0, 0, 0 },
                { 0, 0, 1, 0, 0 },
                { 0, 0, 1, 0, 0 },
                { 0, 0, 1, 1, 0 },
                { 0, 0, 0, 0, 0 },
                }});
        return p;
    }

    static piece
    create_o()
    {
        static piece p({{
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 },
                { 0, 0, 1, 1, 0 },
                { 0, 0, 1, 1, 0 },
                { 0, 0, 0, 0, 0 },
                }}, true);
        return p;
    }

    static piece
    create_z()
    {
        static piece p({{
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 1, 0 },
                { 0, 0, 1, 1, 0 },
                { 0, 0, 1, 0, 0 },
                { 0, 0, 0, 0, 0 },
                }});
        return p;
    }

    static piece
    create_t()
    {
        static piece p({{
                { 0, 0, 0, 0, 0 },
                { 0, 0, 1, 0, 0 },
                { 0, 0, 1, 1, 0 },
                { 0, 0, 1, 0, 0 },
                { 0, 0, 0, 0, 0 },
                }});
        return p;
    }

    static piece
    create_i()
    {
        static piece p({{
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 },
                { 0, 1, 1, 1, 1 },
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 },
                }});
        return p;
    }

};

}

#endif // !defined(_LOZTI_PIECE_HPP_)

// vim:set sw=4 ts=4 et tw=120:
