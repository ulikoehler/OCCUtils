#include "occutils/Axis.hxx"
#include "occutils/Axis.hxx"
#include "occutils/Direction.hxx"
#include "occutils/Point.hxx"

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