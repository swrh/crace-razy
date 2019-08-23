#include <iostream>

#include <boost/test/unit_test.hpp>

#include <lozti/core/block_factory.hpp>

using lozti::block_factory;

BOOST_AUTO_TEST_SUITE(test_suite_block_factory)

BOOST_AUTO_TEST_CASE(test_case)
{
    block_factory factory;

    BOOST_REQUIRE_EQUAL(factory.size(), 7);
}

BOOST_AUTO_TEST_SUITE_END()

// vim:set sw=4 ts=4 et tw=120:
