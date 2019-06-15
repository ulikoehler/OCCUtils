#include "occutils/Plane.hxx"
#include "occutils/Exceptions.hxx"
#include "occutils/Equality.hxx"

gp_Pln OCCUtils::Plane::FromPoints(const gp_Pnt& pO, const gp_Pnt& pX, const gp_Pnt& pY) {
    if(pO == pX) {
        throw OCCConstructionFailedException("Plane construction failed: pO coincides with pX");
    } else if(pO == pY) {
        throw OCCConstructionFailedException("Plane construction failed: pO coincides with pY");
    } else if(pX == pY) {
        throw OCCConstructionFailedException("Plane construction failed: pX coincides with pY");
    }
    gp_Dir xAx(gp_Vec(pO, pX));
    gp_Dir yAx(gp_Vec(pO, pY));
    if(!xAx.IsNormal(yAx, Precision::Angular())) {
        throw OCCConstructionFailedException("Plane construction failed: Axes are not normal to each other");
    }
    // Ax3 takes normal axis
    gp_Dir normal = xAx.Crossed(yAx);
    return gp_Pln(gp_Ax3(pO, normal, xAx));
}