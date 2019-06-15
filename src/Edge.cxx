#include "occutils/Edge.hxx"
#include "occutils/Equality.hxx"
#include <Precision.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>

TopoDS_Edge OCCUtils::Edge::FromPoints (const gp_Pnt& p1, const gp_Pnt& p2) {
    // Are the two points coincident?
    // If so, return an "empty" edge
    if (p1 == p2) {
        return TopoDS_Edge ();
    }
    // Not the same => Create a linear edge
    return BRepBuilderAPI_MakeEdge(p1, p2).Edge();
}