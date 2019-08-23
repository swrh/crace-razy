#include <iostream>
#include <iomanip>

#include <boost/test/unit_test.hpp>

#include <lozti/core/algorithm.hpp>
#include <lozti/core/array_matrix.hpp>

using namespace std;

using lozti::make_array_matrix;

BOOST_AUTO_TEST_SUITE(test_suite_array_matrix)

BOOST_AUTO_TEST_CASE(test_case)
{
    std::size_t i;
    auto m = make_array_matrix<int, 5, 3>();

    i = 0;
    for (std::size_t y = 0; y < m.height(); ++y) {
        for (std::size_t x = 0; x < m.width(); ++x) {
            m.at(x, y) = i++;
        }
    }

    auto n = m;

    i = 0;
    for (std::size_t y = 0; y < m.height(); ++y) {
        for (std::size_t x = 0; x < m.width(); ++x) {
            BOOST_REQUIRE_EQUAL(m.at(x, y), i++);
        }
    }

    for (std::size_t y = m.height(); y > 0; --y) {
        for (std::size_t x = m.width(); x > 0; --x) {
            BOOST_REQUIRE_EQUAL(m.at(x - 1, y - 1), --i);
        }
    }

    BOOST_REQUIRE_EQUAL(m.width(), n.width());
    BOOST_REQUIRE_EQUAL(m.height(), n.height());

    for (std::size_t y = 0; y < m.height(); ++y) {
        for (std::size_t x = 0; x < m.width(); ++x) {
            BOOST_REQUIRE_EQUAL(m.at(x, y), n.at(x, y));
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()

// vim:set sw=4 ts=4 et tw=120:
