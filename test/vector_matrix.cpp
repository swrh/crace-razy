#include <iostream>
#include <iomanip>

#include <boost/test/unit_test.hpp>

#include <lozti/algorithm.hpp>
#include <lozti/vector_matrix.hpp>

using namespace std;

using lozti::make_vector_matrix;
using lozti::transpose;

BOOST_AUTO_TEST_SUITE(test_suite_vector_matrix)

BOOST_AUTO_TEST_CASE(test_case)
{
    auto m = make_vector_matrix<int>(5, 3);

    std::size_t i = 0;
    for (std::size_t y = 0; y < m.height(); ++y) {
        for (std::size_t x = 0; x < m.width(); ++x) {
            m(x, y) = i++;
        }
    }

    for (std::size_t y = 0; y < m.height(); ++y) {
        for (std::size_t x = 0; x < m.width(); ++x) {
            cout << " " << setw(3) << m(x, y);
        }
        cout << endl;
    }
    cout << endl;

    transpose(m);

    for (std::size_t y = 0; y < m.height(); ++y) {
        for (std::size_t x = 0; x < m.width(); ++x) {
            cout << " " << setw(3) << m(x, y);
        }
        cout << endl;
    }
    cout << endl;
}

BOOST_AUTO_TEST_SUITE_END()

// vim:set sw=4 ts=4 et tw=120:
