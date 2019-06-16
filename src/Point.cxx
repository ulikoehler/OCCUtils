#include "occutils/Point.hxx"

gp_Pnt OCCUtils::Point::Origin() {
    return gp_Pnt();
}

gp_Pnt operator+(const gp_Pnt &a, const gp_Pnt &b){
    return gp_Pnt(a.X() + b.X(), a.Y() + b.Y(), a.Z() + b.Z());
}

gp_Pnt operator-(const gp_Pnt &a, const gp_Pnt &b){
    return gp_Pnt(a.X() - b.X(), a.Y() - b.Y(), a.Z() - b.Z());
}