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
    block::matrix_type p0(1, 4);

    fill(p0.begin(), p0.end(), true);

    block bl(p0);

    BOOST_REQUIRE_EQUAL(bl.size(), 2);

    block::iterator it = bl.iterate();

    BOOST_REQUIRE_EQUAL(p0.size(), it->size());
    BOOST_REQUIRE_EQUAL(bl.at(0), *it);
    BOOST_REQUIRE_NE(bl.at(1), *it);
    BOOST_REQUIRE_EQUAL(p0, *it);

    ++it;

    BOOST_REQUIRE_EQUAL(p0.size(), it->size());
    BOOST_REQUIRE_NE(bl.at(0), *it);
    BOOST_REQUIRE_EQUAL(bl.at(1), *it);
    BOOST_REQUIRE_NE(p0, *it);

    ++it;

    BOOST_REQUIRE_EQUAL(p0.size(), it->size());
    BOOST_REQUIRE_EQUAL(bl.at(0), *it);
    BOOST_REQUIRE_NE(bl.at(1), *it);
    BOOST_REQUIRE_EQUAL(p0, *it);
}

BOOST_AUTO_TEST_SUITE_END()

// vim:set sw=4 ts=4 et tw=120:
