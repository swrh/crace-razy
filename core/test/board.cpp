#include <boost/test/unit_test.hpp>

#include <lozti/core/board.hpp>

#include <lozti/core/block_factory.hpp>
#include <lozti/core/block.hpp>
#include <lozti/core/point.hpp>
#include <lozti/core/types.hpp>

using lozti::board;

using lozti::block;
using lozti::block_factory;
using lozti::point;
using lozti::size_type;

BOOST_AUTO_TEST_SUITE(test_suite_board)

BOOST_AUTO_TEST_CASE(test_case)
{
    block_factory blocks;

    for (auto b = blocks.begin(); b != blocks.end(); ++b) {
        board brd(100, 100);

        const board::matrix_type &matrix = brd.matrix();

        BOOST_REQUIRE_EQUAL(matrix.size(), 100 * 100);
        for (board::matrix_type::const_iterator it = matrix.cbegin(); it != matrix.cend(); ++it) {
            BOOST_REQUIRE_EQUAL(*it, false);
        }

        board::movable_block &blk = brd.push(*b);

        size_type left = 0;
        size_type right = brd.width() - blk.matrix().width();
        size_type hcenter = right / 2;

        size_type top = 0;
        size_type bottom = brd.height() - blk.matrix().height();
        size_type vcenter = bottom / 2;

        BOOST_REQUIRE_EQUAL(blk.position(), point(left, top));

        BOOST_REQUIRE_EQUAL(blk.move_right(), true);

        BOOST_REQUIRE_EQUAL(blk.position(), point(right, top));

        BOOST_REQUIRE_EQUAL(blk.move_bottom(), true);

        BOOST_REQUIRE_EQUAL(blk.position(), point(right, bottom));

        BOOST_REQUIRE_EQUAL(blk.move_left(), true);

        BOOST_REQUIRE_EQUAL(blk.position(), point(left, bottom));

        BOOST_REQUIRE_EQUAL(blk.move_top(), true);

        BOOST_REQUIRE_EQUAL(blk.position(), point(left, top));

        BOOST_REQUIRE_EQUAL(blk.center_horizontally(), true);

        BOOST_REQUIRE_EQUAL(blk.position(), point(hcenter, top));

        BOOST_REQUIRE_EQUAL(blk.center_vertically(), true);

        BOOST_REQUIRE_EQUAL(blk.position(), point(hcenter, vcenter));

        BOOST_REQUIRE_EQUAL(blk.step_left(), true);

        BOOST_REQUIRE_EQUAL(blk.position(), point(hcenter - 1, vcenter));

        BOOST_REQUIRE_EQUAL(blk.step_up(), true);

        BOOST_REQUIRE_EQUAL(blk.position(), point(hcenter - 1, vcenter - 1));

        BOOST_REQUIRE_EQUAL(blk.step_right(), true);
        BOOST_REQUIRE_EQUAL(blk.step_right(), true);

        BOOST_REQUIRE_EQUAL(blk.position(), point(hcenter + 1, vcenter - 1));

        BOOST_REQUIRE_EQUAL(blk.step_down(), true);
        BOOST_REQUIRE_EQUAL(blk.step_down(), true);

        BOOST_REQUIRE_EQUAL(blk.position(), point(hcenter + 1, vcenter + 1));

        BOOST_REQUIRE_EQUAL(blk.rotate_clockwise(), true);

        BOOST_REQUIRE_EQUAL(blk.rotate_counterclockwise(), true);

        BOOST_REQUIRE_EQUAL(blk.drop(), true);
    }
}

BOOST_AUTO_TEST_SUITE_END()

// vim:set sw=4 ts=4 et tw=120:
