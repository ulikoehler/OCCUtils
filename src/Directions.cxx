#include "occutils/Directions.hxx"
#include <gp_XYZ.hxx>

gp_Dir OCCUtils::Directions::X() {
    return gp_Dir(gp_XYZ(1.0, 0.0, 0.0));
}

gp_Dir OCCUtils::Directions::Y() {
    return gp_Dir(gp_XYZ(0.0, 1.0, 0.0));
}

gp_Dir OCCUtils::Directions::Z() {
    return gp_Dir(gp_XYZ(0.0, 0.0, 1.0));
}