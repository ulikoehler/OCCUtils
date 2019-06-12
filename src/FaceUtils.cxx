#include "FaceUtils.hxx"
#include <GProp_GProps.hxx>
#include <BRepGProp.hxx>

double SurfaceArea(const TopoDS_Shape& face) {
    GProp_GProps gprops;
    BRepGProp::SurfaceProperties(face, gprops);
    return gprops.Mass();
}
