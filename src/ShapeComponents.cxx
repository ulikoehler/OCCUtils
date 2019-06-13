#include "occutils/ShapeComponents.hxx"
#include "occutils/Exceptions.hxx"
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopExp.hxx>
#include <TopoDS.hxx>

std::vector<TopoDS_Solid> OCCUtils::ShapeComponents::AllSolidsWithin(const TopoDS_Shape& shape) {
    TopTools_IndexedMapOfShape solidShapes;
    TopExp::MapShapes (shape, TopAbs_SOLID, solidShapes);

    std::vector<TopoDS_Solid> solids;
    for (int i = 1; i <= solidShapes.Extent (); i++) {
        solids.push_back (TopoDS::Solid (solidShapes (i)));
    }
    return solids;
}

std::vector<TopoDS_Face> OCCUtils::ShapeComponents::AllFacesWithin(const TopoDS_Shape& shape) {
    TopTools_IndexedMapOfShape faceShapes;
    TopExp::MapShapes (shape, TopAbs_FACE, faceShapes);

    std::vector<TopoDS_Face> faces;
    for (int i = 1; i <= faceShapes.Extent (); i++) {
        faces.push_back (TopoDS::Face (faceShapes (i)));
    }
    return faces;
}

std::vector<TopoDS_Edge> OCCUtils::ShapeComponents::AllEdgesWithin(const TopoDS_Shape& shape) {
    TopTools_IndexedMapOfShape edgeShapes;
    TopExp::MapShapes (shape, TopAbs_EDGE, edgeShapes);

    std::vector<TopoDS_Edge> edges;
    for (int i = 1; i <= edgeShapes.Extent (); i++)
        edges.push_back (TopoDS::Edge (edgeShapes (i)));

    return edges;
}

std::vector<TopoDS_Wire> OCCUtils::ShapeComponents::AllWiresWithin(const TopoDS_Shape& shape) {
    TopTools_IndexedMapOfShape wireShapes;
    TopExp::MapShapes (shape, TopAbs_WIRE, wireShapes);

    std::vector<TopoDS_Wire> wires;
    for (int i = 1; i <= wireShapes.Extent (); i++) {
        wires.push_back (TopoDS::Wire (wireShapes (i)));
    }
    return wires;
}

std::vector<TopoDS_Vertex> OCCUtils::ShapeComponents::AllVerticesWithin(const TopoDS_Shape& shape) {
    TopTools_IndexedMapOfShape vertexShapes;
    TopExp::MapShapes (shape, TopAbs_VERTEX, vertexShapes);

    std::vector<TopoDS_Vertex> vertices;
    for (int i = 1; i <= vertexShapes.Extent (); i++) {
        vertices.push_back (TopoDS::Vertex (vertexShapes (i)));
    }
    return vertices;
}


std::optional<TopoDS_Solid> OCCUtils::ShapeComponents::TryGetSingleSolid (const TopoDS_Shape& shape) {
    // Is shape itself a solid?
    if(shape.ShapeType() == TopAbs_SOLID) {
        return TopoDS::Solid(shape);
    }
    // Else, expect there to be ONE sub-solid
    auto solids = ShapeComponents::AllSolidsWithin(shape);
    if(solids.empty() || solids.size() > 1) {
        return std::nullopt;
    } else {
        return solids[0];
    }
}

std::optional<TopoDS_Face> OCCUtils::ShapeComponents::TryGetSingleFace (const TopoDS_Shape& shape) {
    // Is shape itself a solid?
    if(shape.ShapeType() == TopAbs_FACE) {
        return TopoDS::Face(shape);
    }
    // Else, expect there to be ONE sub-face
    auto faces = ShapeComponents::AllFacesWithin(shape);
    if(faces.empty() || faces.size() > 1) {
        return std::nullopt;
    } else {
        return faces[0];
    }
}

std::optional<TopoDS_Edge> OCCUtils::ShapeComponents::TryGetSingleEdge (const TopoDS_Shape& shape) {
    // Is shape itself an edge?
    if(shape.ShapeType() == TopAbs_EDGE) {
        return TopoDS::Edge(shape);
    }
    // Else, expect there to be ONE sub-edge
    auto edges = ShapeComponents::AllEdgesWithin(shape);
    if(edges.empty() || edges.size() > 1) {
        return std::nullopt;
    } else {
        return edges[0];
    }
}

std::optional<TopoDS_Wire> OCCUtils::ShapeComponents::TryGetSingleWire (const TopoDS_Shape& shape) {
    // Is shape itself a solid?
    if(shape.ShapeType() == TopAbs_WIRE) {
        return TopoDS::Wire(shape);
    }
    // Else, expect there to be ONE sub-wire
    auto wires = ShapeComponents::AllWiresWithin(shape);
    if(wires.empty() || wires.size() > 1) {
        return std::nullopt;
    } else {
        return wires[0];
    }
}

std::optional<TopoDS_Vertex> OCCUtils::ShapeComponents::TryGetSingleVertex (const TopoDS_Shape& shape) {
    // Is shape itself a solid?
    if(shape.ShapeType() == TopAbs_VERTEX) {
        return TopoDS::Vertex(shape);
    }
    // Else, expect there to be ONE sub-vertex
    auto vertices = ShapeComponents::AllVerticesWithin(shape);
    if(vertices.empty() || vertices.size() > 1) {
        return std::nullopt;
    } else {
        return vertices[0];
    }
}

TopoDS_Solid OCCUtils::ShapeComponents::GetSingleSolid (const TopoDS_Shape& shape) {
    auto opt = TryGetSingleSolid(shape);
    if(!opt.has_value()) {
        throw new OCCTopologyCountMismatchException("Shape is not a solid and does not contain a single solid");
    }
    return opt.value();
}

TopoDS_Face OCCUtils::ShapeComponents::GetSingleFace (const TopoDS_Shape& shape) {
    auto opt = TryGetSingleFace(shape);
    if(!opt.has_value()) {
        throw new OCCTopologyCountMismatchException("Shape is not a face and does not contain a single face");
    }
    return opt.value();
}

TopoDS_Edge OCCUtils::ShapeComponents::GetSingleEdge (const TopoDS_Shape& shape) {
    auto opt = TryGetSingleEdge(shape);
    if(!opt.has_value()) {
        throw new OCCTopologyCountMismatchException("Shape is not a edge and does not contain a single edge");
    }
    return opt.value();
}

TopoDS_Wire OCCUtils::ShapeComponents::GetSingleWire (const TopoDS_Shape& shape) {
    auto opt = TryGetSingleWire(shape);
    if(!opt.has_value()) {
        throw new OCCTopologyCountMismatchException("Shape is not a wire and does not contain a single wire");
    }
    return opt.value();
}

TopoDS_Vertex OCCUtils::ShapeComponents::GetSingleVertex (const TopoDS_Shape& shape) {
    auto opt = TryGetSingleVertex(shape);
    if(!opt.has_value()) {
        throw new OCCTopologyCountMismatchException("Shape is not a vertex and does not contain a single vertex");
    }
    return opt.value();
}
