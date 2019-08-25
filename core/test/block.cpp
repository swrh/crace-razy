#include <algorithm>

#include <boost/test/unit_test.hpp>

#include <lozti/core/block.hpp>

using std::fill;

using lozti::block;
using lozti::block_data;

BOOST_AUTO_TEST_SUITE(test_suite_block)

BOOST_AUTO_TEST_CASE(test_case)
{
    block_data::matrix_type p0(1, 4);

    fill(p0.begin(), p0.end(), true);

    block_data bl(p0);

    BOOST_REQUIRE_EQUAL(bl.size(), 2);

    block b(bl);

    BOOST_REQUIRE_EQUAL(p0.size(), b.matrix().size());
    BOOST_REQUIRE_EQUAL(bl.at(0), b.matrix());
    BOOST_REQUIRE_NE(bl.at(1), b.matrix());
    BOOST_REQUIRE_EQUAL(p0, b.matrix());

    b.rotate_clockwise();

    BOOST_REQUIRE_EQUAL(p0.size(), b.matrix().size());
    BOOST_REQUIRE_NE(bl.at(0), b.matrix());
    BOOST_REQUIRE_EQUAL(bl.at(1), b.matrix());
    BOOST_REQUIRE_NE(p0, b.matrix());

    b.rotate_clockwise();

    BOOST_REQUIRE_EQUAL(p0.size(), b.matrix().size());
    BOOST_REQUIRE_EQUAL(bl.at(0), b.matrix());
    BOOST_REQUIRE_NE(bl.at(1), b.matrix());
    BOOST_REQUIRE_EQUAL(p0, b.matrix());
}

BOOST_AUTO_TEST_SUITE_END()

// vim:set sw=4 ts=4 et tw=120:
