#include <array>

#include <boost/test/unit_test.hpp>

#include <lozti/piece.hpp>

using std::array;

using lozti::piece;

BOOST_AUTO_TEST_SUITE(test_suite_piece)

BOOST_AUTO_TEST_CASE(test_case_o)
{
    piece left(piece::create_o());
    piece right(piece::create_o());

    const piece::matrix_type &left_board = left.board();
    const piece::matrix_type &right_board = right.board();

    for (int i = 0; i < 4; i++) {
        right.rotate();

        for (std::size_t y = 0; y < left.size(); y++) {
            const piece::line_type &left_line = left_board.at(y);
            const piece::line_type &right_line = right_board.at(y);
            BOOST_REQUIRE_EQUAL_COLLECTIONS(left_line.begin(), left_line.end(), right_line.begin(), right_line.end());
        }

        right.mirror();

        for (std::size_t y = 0; y < left.size(); y++) {
            const piece::line_type &left_line = left_board.at(y);
            const piece::line_type &right_line = right_board.at(y);
            BOOST_REQUIRE_EQUAL_COLLECTIONS(left_line.begin(), left_line.end(), right_line.begin(), right_line.end());
        }
    }
}

BOOST_AUTO_TEST_CASE(test_case_lzti)
{
    array<piece, 4> lzti = {{
        piece::create_l(),
        piece::create_z(),
        piece::create_t(),
        piece::create_i(),
    }};

    for (auto &pc : lzti) {
        for (std::size_t y = 0; y < pc.size(); y++) {
            const piece::line_type &current = pc.board().at(y);
            const piece::line_type &opposite = pc.board().at(pc.size() - y - 1);

            piece::line_type copy(current);

            pc.mirror();

            BOOST_REQUIRE_EQUAL_COLLECTIONS(copy.begin(), copy.end(), current.rbegin(), current.rend());

            pc.rotate();
            pc.rotate();

            BOOST_REQUIRE_EQUAL_COLLECTIONS(copy.begin(), copy.end(), opposite.begin(), opposite.end());

            pc.mirror();

            BOOST_REQUIRE_EQUAL_COLLECTIONS(copy.begin(), copy.end(), opposite.rbegin(), opposite.rend());

            pc.rotate();
            pc.rotate();

            BOOST_REQUIRE_EQUAL_COLLECTIONS(copy.begin(), copy.end(), current.begin(), current.end());
        }
    }
}

BOOST_AUTO_TEST_CASE(test_case_lzti_simpler)
{
    array<array<piece, 2>, 4> lzti = {{
        { piece::create_l(), piece::create_l(), },
        { piece::create_z(), piece::create_z(), },
        { piece::create_t(), piece::create_t(), },
        { piece::create_i(), piece::create_i(), },
    }};

    const std::size_t size = piece::size();

    for (auto &pieces : lzti) {
        piece &left = pieces.at(0);
        piece &right = pieces.at(1);

        const piece::matrix_type &left_board = left.board();
        const piece::matrix_type &right_board = right.board();

        for (std::size_t y = 0; y < size; y++) {
            const piece::line_type &left_line = left_board.at(y);
            const piece::line_type &right_line = right_board.at(y);
            BOOST_REQUIRE_EQUAL_COLLECTIONS(left_line.begin(), left_line.end(), right_line.begin(), right_line.end());
        }

        right.mirror();

        for (std::size_t y = 0; y < size; y++) {
            const piece::line_type &left_line = left_board.at(y);
            const piece::line_type &right_line = right_board.at(y);
            BOOST_REQUIRE_EQUAL_COLLECTIONS(left_line.begin(), left_line.end(), right_line.rbegin(), right_line.rend());
        }

        right.rotate();
        right.rotate();

        for (std::size_t y = 0; y < size; y++) {
            const piece::line_type &left_line = left_board.at(y);
            const piece::line_type &right_line = right_board.at(size - y - 1);
            BOOST_REQUIRE_EQUAL_COLLECTIONS(left_line.begin(), left_line.end(), right_line.begin(), right_line.end());
        }

        right.mirror();

        for (std::size_t y = 0; y < size; y++) {
            const piece::line_type &left_line = left_board.at(y);
            const piece::line_type &right_line = right_board.at(size - y - 1);
            BOOST_REQUIRE_EQUAL_COLLECTIONS(left_line.begin(), left_line.end(), right_line.rbegin(), right_line.rend());
        }

        right.rotate();
        right.rotate();
    }
}

BOOST_AUTO_TEST_SUITE_END()

// vim:set sw=4 ts=4 et tw=120:
