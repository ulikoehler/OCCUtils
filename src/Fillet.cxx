#include "occutils/Fillet.hxx"

#include <BRepFilletAPI_MakeFillet.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopExp.hxx>
#include <TopoDS.hxx>
#include <numeric>

TopoDS_Shape OCCUtils::Fillet::FilletAll(const TopoDS_Shape& shape, double radius) {
    
    BRepFilletAPI_MakeFillet filletMaker(shape);
    // Iterate edges
    TopTools_IndexedMapOfShape edges;
    TopExp::MapShapes (shape, TopAbs_EDGE, edges);

    for (size_t i = 1; i <= edges.Extent(); i++) {
        const TopoDS_Edge& edge = TopoDS::Edge(edges(i));
        filletMaker.Add(radius, edge);
    }
    filletMaker.Build();
    return filletMaker.Shape();
}

TopoDS_Shape OCCUtils::Fillet::FilletAdaptiveRadius(const TopoDS_Shape& shape, std::function<double(const TopoDS_Edge&)> radiusByEdge) {
    
    BRepFilletAPI_MakeFillet filletMaker(shape);
    // Iterate edges
    TopTools_IndexedMapOfShape edges;
    TopExp::MapShapes (shape, TopAbs_EDGE, edges);

    for (size_t i = 1; i <= edges.Extent(); i++) {
        const TopoDS_Edge& edge = TopoDS::Edge(edges(i));
        double radius = radiusByEdge(edge);
        if(!std::isnan(radius)) { // NaN => dont fillet this edge!
            filletMaker.Add(radius, edge);
        }
    }
    filletMaker.Build();
    return filletMaker.Shape();
}
