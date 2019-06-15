#include "occutils/Equality.hxx"
#include <Precision.hxx>

bool operator==(const gp_Pnt &a, const gp_Pnt &b) {
    return a.IsEqual(b, Precision::Confusion());
}

bool operator!=(const gp_Pnt &a, const gp_Pnt &b) { return !(a == b); }
