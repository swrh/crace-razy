#include <iostream>
#include <iomanip>

#include <boost/test/unit_test.hpp>

#include <lozti/algorithm.hpp>
#include <lozti/vector_matrix.hpp>

using namespace std;

using lozti::flip_lr;
using lozti::flip_ud;
using lozti::transpose;

using lozti::vector_matrix;

struct
F
{
    vector_matrix<int> m, n;

    F()
    : m(5, 3), n(5, 3)
    {
        int i = 0;
        for (std::size_t y = 0; y < m.height(); ++y) {
            for (std::size_t x = 0; x < m.width(); ++x) {
                m(x, y) = i++;
            }
        }

        n = m;
    }
};

BOOST_FIXTURE_TEST_CASE(test_case_flip_lr, F)
{
    flip_lr(n);

    BOOST_REQUIRE_EQUAL(m.width(), n.width());
    BOOST_REQUIRE_EQUAL(m.height(), n.height());

    for (std::size_t y = 0; y < m.height(); ++y) {
        for (std::size_t x = 0; x < m.width(); ++x) {
            BOOST_REQUIRE_EQUAL(m.at(x, y), n.at(n.width() - x - 1, y));
        }
    }
}

BOOST_FIXTURE_TEST_CASE(test_case_flip_ud, F)
{
    flip_ud(n);

    BOOST_REQUIRE_EQUAL(m.width(), n.width());
    BOOST_REQUIRE_EQUAL(m.height(), n.height());

    for (std::size_t y = 0; y < m.height(); ++y) {
        for (std::size_t x = 0; x < m.width(); ++x) {
            BOOST_REQUIRE_EQUAL(m.at(x, y), n.at(x, n.height() - y - 1));
        }
    }
}

BOOST_FIXTURE_TEST_CASE(test_case_transpose, F)
{
    transpose(n);

    BOOST_REQUIRE_EQUAL(m.width(), n.height());
    BOOST_REQUIRE_EQUAL(m.height(), n.width());

    for (std::size_t y = 0; y < m.height(); ++y) {
        for (std::size_t x = 0; x < m.width(); ++x) {
            BOOST_REQUIRE_EQUAL(m.at(x, y), n.at(y, x));
        }
    }
}

// vim:set sw=4 ts=4 et tw=120:
