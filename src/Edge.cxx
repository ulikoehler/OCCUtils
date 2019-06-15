#include "occutils/Edge.hxx"
#include <Precision.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>

TopoDS_Edge OCCUtils::Edge::FromPoints (const gp_Pnt& p1, const gp_Pnt& p2) {
    // Are the two points the same?
    // If so, return an "empty" edge
    if (p1.Distance(p2) <= Precision::Confusion()) {
        return TopoDS_Edge ();
    }
    // Not the same => Create a linear edge
    return BRepBuilderAPI_MakeEdge(p1, p2).Edge();
}