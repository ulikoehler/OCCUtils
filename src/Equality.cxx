#include "occutils/Equality.hxx"
#include <Precision.hxx>

bool operator==(const gp_Pnt &a, const gp_Pnt &b) {
    return a.IsEqual(b, Precision::Confusion());
}

bool operator!=(const gp_Pnt &a, const gp_Pnt &b) {
    return !(a == b);
}

bool operator==(const gp_XYZ &a, const gp_XYZ &b){
    return a.IsEqual(b, Precision::Confusion());
}

bool operator!=(const gp_XYZ &a, const gp_XYZ &b){
    return !(a == b);
}

bool operator==(const gp_Pnt2d &a, const gp_Pnt2d &b) {
    return a.IsEqual(b, Precision::Confusion());
}

bool operator!=(const gp_Pnt2d &a, const gp_Pnt2d &b) {
    return !(a == b);
}

bool operator==(const gp_XY &a, const gp_XY &b) {
    return a.IsEqual(b, Precision::Confusion());

}

bool operator!=(const gp_XY &a, const gp_XY &b) {
    return !(a == b);
}

bool operator==(const gp_Vec &a, const gp_Vec &b){
    return a.IsEqual(b, Precision::Confusion(), Precision::Angular());
}

bool operator!=(const gp_Vec &a, const gp_Vec &b){
    return !(a == b);
}
