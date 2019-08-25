#include <boost/test/unit_test.hpp>

#include <lozti/core/board.hpp>

#include <lozti/core/block_factory.hpp>
#include <lozti/core/block.hpp>

using lozti::board;

using lozti::block;
using lozti::block_factory;

BOOST_AUTO_TEST_SUITE(test_suite_board)

BOOST_AUTO_TEST_CASE(test_case)
{
    block_factory blocks;

    board brd(100, 100);

    const board::container_type &data = brd.get_data();

    BOOST_REQUIRE_EQUAL(data.size(), 100 * 100);
    for (board::container_type::const_iterator it = data.cbegin(); it != data.cend(); ++it) {
        BOOST_REQUIRE_EQUAL(*it, false);
    }

#if 0
    auto x = brd.insert(blocks.make_random());

    x.move_center();
    x.move_top();
    x.step_left();
    x.step_right();
    x.step_down();
    x.rotate_clockwise();
    x.move_bottom();
#endif
}

BOOST_AUTO_TEST_SUITE_END()

// vim:set sw=4 ts=4 et tw=120:
