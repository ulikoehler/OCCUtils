#include "occutils/MakePrimitive.hxx"
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>

using namespace OCCUtils;

TopoDS_Solid OCCUtils::Primitives::MakeBox(
    double xSize, double ySize, double zSize,
    int center,
    gp_Pnt origin) {
    // Compute offsets based on centering
    if(center & CenterX) {
        origin.SetX(origin.X() - xSize / 2.0);
    }
    if(center & CenterY) {
        origin.SetY(origin.Y() - ySize / 2.0);
    }
    if(center & CenterZ) {
        origin.SetZ(origin.Z() - zSize / 2.0);
    }
    // Build primitive
    BRepPrimAPI_MakeBox box(origin, xSize, ySize, zSize);
    box.Build();
    return box.Solid();

}

TopoDS_Solid OCCUtils::Primitives::MakeCylinder(
    double diameter, double length,
    int center,
    gp_Pnt origin) {
    // Compute offsets based on centering
    if(center & CenterD) {
        origin.SetX(origin.X() - diameter / 2.0);
        origin.SetY(origin.Y() - diameter / 2.0);
    }
    if(center & CenterL) {
        origin.SetZ(origin.Z() - length / 2.0);
    }
    // Build primitive
    gp_Ax2 ax;
    BRepPrimAPI_MakeCylinder cyl(ax, diameter / 2.0, length);
    cyl.Build();
    return cyl.Solid();
}