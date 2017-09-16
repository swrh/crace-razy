#include <algorithm>

#include <boost/test/unit_test.hpp>

#include <lozti/block.hpp>
#include <lozti/vector_matrix.hpp>

using std::fill;

using lozti::block;
using lozti::vector_matrix;

BOOST_AUTO_TEST_SUITE(test_suite_block)

BOOST_AUTO_TEST_CASE(test_case)
{
    vector_matrix<bool> l(1, 4);

    fill(l.begin(), l.end(), true);

    block bl(l);

    BOOST_REQUIRE_EQUAL(bl.size(), 2);

    block::iterator bli = bl.iterate();

    BOOST_REQUIRE_EQUAL(bl.at(0), *bli);
    BOOST_REQUIRE_NE(bl.at(1), *bli);

    ++bli;

    BOOST_REQUIRE_NE(bl.at(0), *bli);
    BOOST_REQUIRE_EQUAL(bl.at(1), *bli);

    ++bli;

    BOOST_REQUIRE_EQUAL(bl.at(0), *bli);
    BOOST_REQUIRE_NE(bl.at(1), *bli);
}

BOOST_AUTO_TEST_SUITE_END()

// vim:set sw=4 ts=4 et tw=120:
