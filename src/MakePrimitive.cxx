#include "occutils/MakePrimitive.hxx"
#include <BRepPrimAPI_MakeBox.hxx>

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