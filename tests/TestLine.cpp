#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <occutils/Line.hxx>
#include <occutils/Direction.hxx>
#include <occutils/PrintOCC.hxx>

BOOST_AUTO_TEST_CASE( Line2D )
{
    // Intersect between a line and itself has infinite points
    gp_Lin2d lin1(gp_Pnt2d(0, 0), OCCUtils::Direction::X2d());
    auto result = OCCUtils::Line::Intersection(lin1, lin1);
    BOOST_CHECK(!result.has_value());
    // Two intersecting lines should have an intersection point
    gp_Lin2d lin2(gp_Pnt2d(0, -1), OCCUtils::Direction::Y2d());
    result = OCCUtils::Line::Intersection(lin1, lin2);
    BOOST_CHECK(result.has_value());
    BOOST_CHECK_EQUAL(result.value(), gp_Pnt2d(0, 0));
}