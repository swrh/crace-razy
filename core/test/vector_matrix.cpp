#include <iostream>
#include <iomanip>

#include <boost/test/unit_test.hpp>

#include <lozti/core/algorithm.hpp>
#include <lozti/core/vector_matrix.hpp>

using namespace std;

using lozti::make_vector_matrix;

BOOST_AUTO_TEST_SUITE(test_suite_vector_matrix)

BOOST_AUTO_TEST_CASE(test_case)
{
    std::size_t i;
    auto m = make_vector_matrix<int>(5, 3);

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

BOOST_AUTO_TEST_CASE(test_case_swap)
{
    std::size_t i;
    auto m = make_vector_matrix<int>(5, 3);

    BOOST_REQUIRE_EQUAL(m.width(), 5);
    BOOST_REQUIRE_EQUAL(m.height(), 3);
    BOOST_REQUIRE_EQUAL(m.size(), 5 * 3);

    i = 0;
    for (std::size_t y = 0; y < m.height(); ++y) {
        for (std::size_t x = 0; x < m.width(); ++x) {
            m.at(x, y) = i;
            BOOST_REQUIRE_EQUAL(m.at(x, y), i);
            ++i;
        }
    }

    auto n = make_vector_matrix<int>(1, 1);

    BOOST_REQUIRE_EQUAL(n.width(), 1);
    BOOST_REQUIRE_EQUAL(n.height(), 1);
    BOOST_REQUIRE_EQUAL(n.size(), 1);

    for (std::size_t y = 0; y < n.height(); ++y) {
        for (std::size_t x = 0; x < n.width(); ++x) {
            BOOST_REQUIRE_EQUAL(n.at(x, y), 0);
        }
    }

    m.swap(n);

    BOOST_REQUIRE_EQUAL(n.width(), 5);
    BOOST_REQUIRE_EQUAL(n.height(), 3);
    BOOST_REQUIRE_EQUAL(n.size(), 5 * 3);

    i = 0;
    for (std::size_t y = 0; y < n.height(); ++y) {
        for (std::size_t x = 0; x < n.width(); ++x) {
            BOOST_REQUIRE_EQUAL(n.at(x, y), i++);
        }
    }

    BOOST_REQUIRE_EQUAL(m.width(), 1);
    BOOST_REQUIRE_EQUAL(m.height(), 1);
    BOOST_REQUIRE_EQUAL(m.size(), 1);

    for (std::size_t y = 0; y < m.height(); ++y) {
        for (std::size_t x = 0; x < m.width(); ++x) {
            BOOST_REQUIRE_EQUAL(m.at(x, y), 0);
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()

// vim:set sw=4 ts=4 et tw=120:
