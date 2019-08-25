#include <iostream>
#include <iomanip>

#include <boost/test/unit_test.hpp>

#include <lozti/core/algorithm.hpp>
#include <lozti/core/array_matrix.hpp>
#include <lozti/core/types.hpp>

using lozti::make_array_matrix;
using lozti::size_type;

BOOST_AUTO_TEST_SUITE(test_suite_array_matrix)

BOOST_AUTO_TEST_CASE(test_case)
{
    size_type i;
    auto m = make_array_matrix<int, 5, 3>();

    i = 0;
    for (size_type y = 0; y < m.height(); ++y) {
        for (size_type x = 0; x < m.width(); ++x) {
            m.at(x, y) = i++;
        }
    }

    auto n = m;

    i = 0;
    for (size_type y = 0; y < m.height(); ++y) {
        for (size_type x = 0; x < m.width(); ++x) {
            BOOST_REQUIRE_EQUAL(m.at(x, y), i++);
        }
    }

    for (size_type y = m.height(); y > 0; --y) {
        for (size_type x = m.width(); x > 0; --x) {
            BOOST_REQUIRE_EQUAL(m.at(x - 1, y - 1), --i);
        }
    }

    BOOST_REQUIRE_EQUAL(m.width(), n.width());
    BOOST_REQUIRE_EQUAL(m.height(), n.height());

    for (size_type y = 0; y < m.height(); ++y) {
        for (size_type x = 0; x < m.width(); ++x) {
            BOOST_REQUIRE_EQUAL(m.at(x, y), n.at(x, y));
        }
    }
}

BOOST_AUTO_TEST_CASE(test_case_swap)
{
    size_type i;
    auto m = make_array_matrix<int, 5, 3>();

    BOOST_REQUIRE_EQUAL(m.width(), 5);
    BOOST_REQUIRE_EQUAL(m.height(), 3);
    BOOST_REQUIRE_EQUAL(m.size(), 5 * 3);

    i = 0;
    for (size_type y = 0; y < m.height(); ++y) {
        for (size_type x = 0; x < m.width(); ++x) {
            m.at(x, y) = i;
            BOOST_REQUIRE_EQUAL(m.at(x, y), i);
            ++i;
        }
    }

    auto n = make_array_matrix<int, 5, 3>();

    BOOST_REQUIRE_EQUAL(n.width(), 5);
    BOOST_REQUIRE_EQUAL(n.height(), 3);
    BOOST_REQUIRE_EQUAL(n.size(), 5 * 3);

    for (size_type y = 0; y < n.height(); ++y) {
        for (size_type x = 0; x < n.width(); ++x) {
            n.at(x, y) = 0;
            BOOST_REQUIRE_EQUAL(n.at(x, y), 0);
        }
    }

    m.swap(n);

    BOOST_REQUIRE_EQUAL(n.width(), 5);
    BOOST_REQUIRE_EQUAL(n.height(), 3);
    BOOST_REQUIRE_EQUAL(n.size(), 5 * 3);

    i = 0;
    for (size_type y = 0; y < n.height(); ++y) {
        for (size_type x = 0; x < n.width(); ++x) {
            BOOST_REQUIRE_EQUAL(n.at(x, y), i++);
        }
    }

    BOOST_REQUIRE_EQUAL(m.width(), 5);
    BOOST_REQUIRE_EQUAL(m.height(), 3);
    BOOST_REQUIRE_EQUAL(m.size(), 5 * 3);

    for (size_type y = 0; y < m.height(); ++y) {
        for (size_type x = 0; x < m.width(); ++x) {
            BOOST_REQUIRE_EQUAL(m.at(x, y), 0);
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()

// vim:set sw=4 ts=4 et tw=120:
