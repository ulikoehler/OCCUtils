#include "occutils/Direction.hxx"
#include <gp_XYZ.hxx>

gp_Vec operator*(const gp_Dir &a, double factor) {
    return gp_Vec(a.X() * factor, a.Y() * factor, a.Z() * factor);
}

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

/**
 * Get the global 2D X axis direction
 */
gp_Dir2d OCCUtils::Direction::X2d() {
    return gp_Dir2d(gp_XY(1.0, 0.0));
}
/**
 * Get the global 2D -X axis direction
 */
gp_Dir2d OCCUtils::Direction::MinusX2d() {
    return gp_Dir2d(gp_XY(-1.0, 0.0));
}
/**
 * Get the global 2D Y axis direction
 */
gp_Dir2d OCCUtils::Direction::Y2d() {
    return gp_Dir2d(gp_XY(0.0, 1.0));
}
/**
 * Get the global 2D -Y axis direction
 */
gp_Dir2d OCCUtils::Direction::MinusY2d() {
    return gp_Dir2d(gp_XY(0.0, -1.0));
}

gp_Dir OCCUtils::Direction::Orthogonal(const gp_Dir& a, const gp_Dir& b) {
    return a.Crossed(b);
}