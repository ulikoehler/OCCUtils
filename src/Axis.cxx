#include "occutils/Axis.hxx"
#include "occutils/Axis.hxx"
#include "occutils/Direction.hxx"
#include "occutils/Point.hxx"

#include <gp_Lin.hxx>

using namespace OCCUtils;

gp_Ax1 OCCUtils::Ax1::OX() {
    return gp_Ax1(Point::Origin(), Direction::X());
}

gp_Ax1 OCCUtils::Ax1::OY() {
    return gp_Ax1(Point::Origin(), Direction::Y());
}

gp_Ax1 OCCUtils::Ax1::OZ() {
    return gp_Ax1(Point::Origin(), Direction::Z());
}

gp_Ax1 OCCUtils::Ax1::OMinusX() {
    return gp_Ax1(Point::Origin(), Direction::MinusX());
}

gp_Ax1 OCCUtils::Ax1::OMinusY() {
    return gp_Ax1(Point::Origin(), Direction::MinusY());
}

gp_Ax1 OCCUtils::Ax1::OMinusZ() {
    return gp_Ax1(Point::Origin(), Direction::MinusZ());
}

gp_Ax2 OCCUtils::Ax2::FromAx1(const gp_Ax1& axis) {
    return gp_Ax2(axis.Location(), axis.Direction());
}

gp_Ax2 OCCUtils::Ax2::OX() {
    return gp_Ax2(Point::Origin(), Direction::X());
}

gp_Ax2 OCCUtils::Ax2::OY() {
    return gp_Ax2(Point::Origin(), Direction::Y());
}

gp_Ax2 OCCUtils::Ax2::OZ() {
    return gp_Ax2(Point::Origin(), Direction::Z());
}

gp_Ax2 OCCUtils::Ax2::OMinusX() {
    return gp_Ax2(Point::Origin(), Direction::MinusX());
}

gp_Ax2 OCCUtils::Ax2::OMinusY() {
    return gp_Ax2(Point::Origin(), Direction::MinusY());
}

gp_Ax2 OCCUtils::Ax2::OMinusZ() {
    return gp_Ax2(Point::Origin(), Direction::MinusZ());
}

bool OCCUtils::Axis::Contains(const gp_Ax1& axis, const gp_Pnt& pnt, double tolerance) {
    return gp_Lin(axis).Contains(pnt, tolerance);
}

double OCCUtils::Axis::Distance(const gp_Ax1& axis, const gp_Pnt& pnt) {
    return gp_Lin(axis).Distance(pnt);
}

gp_Ax1 operator+(const gp_Ax1& axis, const gp_Vec& vec) {
    return gp_Ax1(axis.Location() + vec, axis.Direction());
}

gp_Ax1 operator+(const gp_Ax1& axis, const gp_XYZ& vec) {
    return gp_Ax1(axis.Location() + vec, axis.Direction());
}