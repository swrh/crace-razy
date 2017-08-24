#if !defined(_LOZTI_PIECE_HPP_)
#define _LOZTI_PIECE_HPP_

#include <algorithm>
#include <array>
#include <stdexcept>
#include <vector>

namespace lozti {

class
piece
{
public:
    typedef char data_type;
    typedef std::vector<data_type> line_type;
    typedef std::vector<line_type> matrix_type;
    typedef matrix_type::size_type size_type;

private:
    matrix_type board_;

    piece(matrix_type &&board, bool symmetric = false)
        : symmetric_(symmetric)
    {
        size_type sz = board.size();

        for (const auto &line : board) {
            if (line.size() != sz)
                throw std::runtime_error("non symmetric matrix passed to piece constructor");
        }

        board_.swap(board);
    }

private:
    bool symmetric_;

public:
    size_type
    size() const
    {
        return board_.size();
    }

    const line_type &
    at(size_type n) const
    {
        return board_.at(n);
    }

public:
    void
    rotate()
    {
        if (symmetric_)
            return;

        size_type sz = size();

        for (size_type y = 0; y < (sz / 2); y++) {
            for (size_type x = y; x < (sz - y - 1); x++) {
                data_type t = board_[y][x];

                std::swap(t, board_[x][sz - y - 1]);
                std::swap(t, board_[sz - y - 1][sz - x - 1]);
                std::swap(t, board_[sz - x - 1][y]);
                std::swap(t, board_[y][x]);
            }
        }
    }

    void
    mirror()
    {
        if (symmetric_)
            return;

        size_type sz = size();

        for (size_type y = 0; y < sz; y++) {
            for (size_type x = 0; x < (sz / 2); x++) {
                std::swap(board_[y][x], board_[y][sz - x - 1]);
            }
        }
    }

public:
    static piece
    create_l()
    {
        static piece pc(matrix_type({
                { 0, 0, 0, 0, 0 },
                { 0, 0, 1, 0, 0 },
                { 0, 0, 1, 0, 0 },
                { 0, 0, 1, 1, 0 },
                { 0, 0, 0, 0, 0 },
                }));
        return pc;
    }

    static piece
    create_o()
    {
        static piece pc(matrix_type{{
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 },
                { 0, 0, 1, 1, 0 },
                { 0, 0, 1, 1, 0 },
                { 0, 0, 0, 0, 0 },
                }}, true);
        return pc;
    }

    static piece
    create_z()
    {
        static piece pc(matrix_type{{
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 1, 0 },
                { 0, 0, 1, 1, 0 },
                { 0, 0, 1, 0, 0 },
                { 0, 0, 0, 0, 0 },
                }});
        return pc;
    }

    static piece
    create_t()
    {
        static piece pc(matrix_type{{
                { 0, 0, 0, 0, 0 },
                { 0, 0, 1, 0, 0 },
                { 0, 0, 1, 1, 0 },
                { 0, 0, 1, 0, 0 },
                { 0, 0, 0, 0, 0 },
                }});
        return pc;
    }

    static piece
    create_i()
    {
        static piece pc(matrix_type{{
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 },
                { 0, 1, 1, 1, 1 },
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 },
                }});
        return pc;
    }

public:
    static piece
    create_random()
    {
        static std::array<piece, 5> pieces({{
                create_l(), create_o(), create_z(), create_t(), create_i(),
                }});
        unsigned int seed = static_cast<unsigned int>(time(NULL));

        auto &pc = pieces.at(rand_r(&seed) % pieces.size());

        unsigned int n;

        n = rand_r(&seed) % 4;
        while (n-- > 0)
            pc.rotate();

        n = rand_r(&seed) % 2;
        while (n-- > 0)
            pc.mirror();

        return pc;
    }

};

}

#endif // !defined(_LOZTI_PIECE_HPP_)

// vim:set sw=4 ts=4 et tw=120:
