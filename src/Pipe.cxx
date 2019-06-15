#include "occutils/Pipe.hxx"
#include <BRepOffsetAPI_MakePipe.hxx>

TopoDS_Shape OCCUtils::Pipe::FromSplineAndProfile(const TopoDS_Wire& wire, const TopoDS_Shape& profile) {
    BRepOffsetAPI_MakePipe makePipe(wire, profile);
    makePipe.Build();
    return makePipe.Shape();
}