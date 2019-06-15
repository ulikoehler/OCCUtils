#include "occutils/Direction.hxx"
#include <gp_XYZ.hxx>

gp_Dir OCCUtils::Direction::X() {
    return gp_Dir(gp_XYZ(1.0, 0.0, 0.0));
}

gp_Dir OCCUtils::Direction::Y() {
    return gp_Dir(gp_XYZ(0.0, 1.0, 0.0));
}

gp_Dir OCCUtils::Direction::Z() {
    return gp_Dir(gp_XYZ(0.0, 0.0, 1.0));
}

gp_Dir OCCUtils::Direction::MinusX() {
    return gp_Dir(gp_XYZ(-1.0, 0.0, 0.0));
}

gp_Dir OCCUtils::Direction::MinusY() {
    return gp_Dir(gp_XYZ(0.0, -1.0, 0.0));
}

gp_Dir OCCUtils::Direction::MinusZ() {
    return gp_Dir(gp_XYZ(0.0, 0.0, -1.0));
}