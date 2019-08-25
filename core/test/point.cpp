#include <boost/test/unit_test.hpp>

#include <lozti/core/point.hpp>

using lozti::point;

BOOST_AUTO_TEST_SUITE(test_suite_point)

BOOST_AUTO_TEST_CASE(test_case_initialize)
{
    point p, q(0, 0), s(1, 1);

    BOOST_REQUIRE_EQUAL(p.x(), 0);
    BOOST_REQUIRE_EQUAL(p.y(), 0);
    BOOST_REQUIRE_EQUAL(p, point(0, 0));
    BOOST_REQUIRE_EQUAL(p, point());

    BOOST_REQUIRE_EQUAL(q.x(), 0);
    BOOST_REQUIRE_EQUAL(q.y(), 0);
    BOOST_REQUIRE_EQUAL(q, point(0, 0));
    BOOST_REQUIRE_EQUAL(q, point());
    BOOST_REQUIRE_EQUAL(q, p);

    BOOST_REQUIRE_EQUAL(s.x(), 1);
    BOOST_REQUIRE_EQUAL(s.y(), 1);
    BOOST_REQUIRE_EQUAL(s, point(1, 1));
    BOOST_REQUIRE_NE(s, point());
    BOOST_REQUIRE_NE(s, p);
    BOOST_REQUIRE_NE(s, q);
}

BOOST_AUTO_TEST_CASE(test_case_add)
{
    point p(2, 2), q(1, 1);

    p = p + q;

    BOOST_REQUIRE_EQUAL(p.x(), 3);
    BOOST_REQUIRE_EQUAL(p.y(), 3);
    BOOST_REQUIRE_EQUAL(p, point(3, 3));
    BOOST_REQUIRE_NE(p, point());
    BOOST_REQUIRE_NE(p, q);

    p = p + p;

    BOOST_REQUIRE_EQUAL(p.x(), 6);
    BOOST_REQUIRE_EQUAL(p.y(), 6);
    BOOST_REQUIRE_EQUAL(p, point(6, 6));
    BOOST_REQUIRE_NE(p, point());
    BOOST_REQUIRE_NE(p, q);

    q += p;

    BOOST_REQUIRE_EQUAL(q.x(), 7);
    BOOST_REQUIRE_EQUAL(q.y(), 7);
    BOOST_REQUIRE_EQUAL(q, point(7, 7));
    BOOST_REQUIRE_NE(q, point());
    BOOST_REQUIRE_NE(q, p);

    q += q;

    BOOST_REQUIRE_EQUAL(q.x(), 14);
    BOOST_REQUIRE_EQUAL(q.y(), 14);
    BOOST_REQUIRE_EQUAL(q, point(14, 14));
    BOOST_REQUIRE_NE(q, point());
    BOOST_REQUIRE_NE(q, p);
}

BOOST_AUTO_TEST_CASE(test_case_subtract)
{
    point p(14, 14), q(3, 3);

    p -= q;

    BOOST_REQUIRE_EQUAL(p.x(), 11);
    BOOST_REQUIRE_EQUAL(p.y(), 11);
    BOOST_REQUIRE_EQUAL(p, point(11, 11));
    BOOST_REQUIRE_NE(p, point());
    BOOST_REQUIRE_NE(p, q);

    p = p - q;

    BOOST_REQUIRE_EQUAL(p.x(), 8);
    BOOST_REQUIRE_EQUAL(p.y(), 8);
    BOOST_REQUIRE_EQUAL(p, point(8, 8));
    BOOST_REQUIRE_NE(p, point());
    BOOST_REQUIRE_NE(p, q);

    p -= p;

    BOOST_REQUIRE_EQUAL(p.x(), 0);
    BOOST_REQUIRE_EQUAL(p.y(), 0);
    BOOST_REQUIRE_EQUAL(p, point(0, 0));
    BOOST_REQUIRE_EQUAL(p, point());
    BOOST_REQUIRE_NE(p, q);

    p -= q;

    BOOST_REQUIRE_EQUAL(p.x(), -3);
    BOOST_REQUIRE_EQUAL(p.y(), -3);
    BOOST_REQUIRE_EQUAL(p, point(-3, -3));
    BOOST_REQUIRE_NE(p, point());
    BOOST_REQUIRE_NE(p, q);
}

BOOST_AUTO_TEST_CASE(test_case_multiply)
{
    point p(2, 2), q(1, 1);

    q = q * q;

    BOOST_REQUIRE_EQUAL(q.x(), 1);
    BOOST_REQUIRE_EQUAL(q.y(), 1);
    BOOST_REQUIRE_EQUAL(q, point(1, 1));
    BOOST_REQUIRE_NE(q, point());
    BOOST_REQUIRE_NE(q, p);

    q = p * p;

    BOOST_REQUIRE_EQUAL(q.x(), 4);
    BOOST_REQUIRE_EQUAL(q.y(), 4);
    BOOST_REQUIRE_EQUAL(q, point(4, 4));
    BOOST_REQUIRE_NE(q, point());
    BOOST_REQUIRE_NE(q, p);

    q *= p;

    BOOST_REQUIRE_EQUAL(q.x(), 8);
    BOOST_REQUIRE_EQUAL(q.y(), 8);
    BOOST_REQUIRE_EQUAL(q, point(8, 8));
    BOOST_REQUIRE_NE(q, point());
    BOOST_REQUIRE_NE(q, p);

    q *= q;

    BOOST_REQUIRE_EQUAL(q.x(), 64);
    BOOST_REQUIRE_EQUAL(q.y(), 64);
    BOOST_REQUIRE_EQUAL(q, point(64, 64));
    BOOST_REQUIRE_NE(q, point());
    BOOST_REQUIRE_NE(q, p);
}

BOOST_AUTO_TEST_CASE(test_case_divide)
{
    point p(2, 2), q(64, 64);

    q = q / p;

    BOOST_REQUIRE_EQUAL(q.x(), 32);
    BOOST_REQUIRE_EQUAL(q.y(), 32);
    BOOST_REQUIRE_EQUAL(q, point(32, 32));
    BOOST_REQUIRE_NE(q, point());
    BOOST_REQUIRE_NE(q, p);

    q /= p;

    BOOST_REQUIRE_EQUAL(q.x(), 16);
    BOOST_REQUIRE_EQUAL(q.y(), 16);
    BOOST_REQUIRE_EQUAL(q, point(16, 16));
    BOOST_REQUIRE_NE(q, point());
    BOOST_REQUIRE_NE(q, p);

    q /= p;
    q /= p;
    q /= p;

    BOOST_REQUIRE_EQUAL(q.x(), 2);
    BOOST_REQUIRE_EQUAL(q.y(), 2);
    BOOST_REQUIRE_EQUAL(q, point(2, 2));
    BOOST_REQUIRE_NE(q, point());
    BOOST_REQUIRE_EQUAL(q, p);

    q /= q;

    BOOST_REQUIRE_EQUAL(q.x(), 1);
    BOOST_REQUIRE_EQUAL(q.y(), 1);
    BOOST_REQUIRE_EQUAL(q, point(1, 1));
    BOOST_REQUIRE_NE(q, point());
    BOOST_REQUIRE_NE(q, p);
}

BOOST_AUTO_TEST_CASE(test_case_ostream)
{
    std::ostringstream os;

    os.str("");
    os << point();
    BOOST_REQUIRE_EQUAL(os.str(), "0,0");

    os.str("");
    os << point(1, 2);
    BOOST_REQUIRE_EQUAL(os.str(), "1,2");
}

BOOST_AUTO_TEST_SUITE_END()

// vim:set sw=4 ts=4 et tw=120:
