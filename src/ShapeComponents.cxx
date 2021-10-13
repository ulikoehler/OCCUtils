#include "occutils/ShapeComponents.hxx"
#include "occutils/Exceptions.hxx"
#include <TopExp_Explorer.hxx>
#include <BRep_Tool.hxx>
#include <TopoDS.hxx>

std::vector<TopoDS_Solid> OCCUtils::ShapeComponents::AllSolidsWithin(const TopoDS_Shape& shape) {
    std::vector<TopoDS_Solid> solids;
    for (TopExp_Explorer solidExplorer(shape, TopAbs_SOLID); solidExplorer.More(); solidExplorer.Next()) {
        const auto &face = TopoDS::Solid(solidExplorer.Current());
        if (face.IsNull()) {
            continue;
        }
        solids.push_back(face);
    }
    return solids;
}

std::vector<TopoDS_Solid> OCCUtils::ShapeComponents::AllSolidsWithin(const std::vector<TopoDS_Shape>& shapes) {
    std::vector<TopoDS_Solid> solids;
    for(const auto& shape : shapes) {
        for (TopExp_Explorer solidExplorer(shape, TopAbs_SOLID); solidExplorer.More(); solidExplorer.Next()) {
            const auto &face = TopoDS::Solid(solidExplorer.Current());
            if (face.IsNull()) {
                continue;
            }
            solids.push_back(face);
        }
    }
    return solids;
}

std::vector<TopoDS_Face> OCCUtils::ShapeComponents::AllFacesWithin(const TopoDS_Shape& shape) {
    std::vector<TopoDS_Face> faces;
    for (TopExp_Explorer faceExplorer(shape, TopAbs_FACE); faceExplorer.More(); faceExplorer.Next()) {
        const auto &face = TopoDS::Face(faceExplorer.Current());
        if (face.IsNull()) {
            continue;
        }
        faces.push_back(face);
    }
    return faces;
}

std::vector<TopoDS_Face> OCCUtils::ShapeComponents::AllFacesWithin(const std::vector<TopoDS_Shape>& shapes) {
    std::vector<TopoDS_Face> faces;
    for(const auto& shape : shapes) {
        for (TopExp_Explorer faceExplorer(shape, TopAbs_FACE); faceExplorer.More(); faceExplorer.Next()) {
            const auto &face = TopoDS::Face(faceExplorer.Current());
            if (face.IsNull()) {
                continue;
            }
            faces.push_back(face);
        }
    }
    return faces;
}

std::vector<TopoDS_Edge> OCCUtils::ShapeComponents::AllEdgesWithin(const TopoDS_Shape& shape) {
    std::vector<TopoDS_Edge> edges;
    for (TopExp_Explorer edgeExplorer(shape, TopAbs_EDGE); edgeExplorer.More(); edgeExplorer.Next()) {
        const auto &edge = TopoDS::Edge(edgeExplorer.Current());
        if (edge.IsNull()) {
            continue;
        }
        edges.push_back(edge);
    }
    return edges;
}

std::vector<TopoDS_Edge> OCCUtils::ShapeComponents::AllEdgesWithin(const std::vector<TopoDS_Shape>& shapes) {

    std::vector<TopoDS_Edge> edges;
    for(const auto& shape : shapes) {
        for (TopExp_Explorer edgeExplorer(shape, TopAbs_EDGE); edgeExplorer.More(); edgeExplorer.Next()) {
            const auto &edge = TopoDS::Edge(edgeExplorer.Current());
            if (edge.IsNull()) {
                continue;
            }
            edges.push_back(edge);
        }
    }
    return edges;
}

std::vector<TopoDS_Edge> OCCUtils::ShapeComponents::AllEdgesWithin(const std::vector<TopoDS_Wire>& shapes) {
    std::vector<TopoDS_Edge> edges;
    for(const auto& shape : shapes) {
        for (TopExp_Explorer edgeExplorer(shape, TopAbs_EDGE); edgeExplorer.More(); edgeExplorer.Next()) {
            const auto &edge = TopoDS::Edge(edgeExplorer.Current());
            if (edge.IsNull()) {
                continue;
            }
            edges.push_back(edge);
        }
    }
    return edges;
}

std::vector<TopoDS_Wire> OCCUtils::ShapeComponents::AllWiresWithin(const TopoDS_Shape& shape) {
    std::vector<TopoDS_Wire> wires;
    for (TopExp_Explorer wireExplorer(shape, TopAbs_WIRE); wireExplorer.More(); wireExplorer.Next()) {
        const auto &wire = TopoDS::Wire(wireExplorer.Current());
        if (wire.IsNull()) {
            continue;
        }
        wires.push_back(wire);
    }
    return wires;
}

std::vector<TopoDS_Wire> OCCUtils::ShapeComponents::AllWiresWithin(const std::vector<TopoDS_Shape>& shapes) {
    std::vector<TopoDS_Wire> wires;
    for(const auto& shape : shapes) {
        for (TopExp_Explorer wireExplorer(shape, TopAbs_WIRE); wireExplorer.More(); wireExplorer.Next()) {
            const auto &wire = TopoDS::Wire(wireExplorer.Current());
            if (wire.IsNull()) {
                continue;
            }
            wires.push_back(wire);
        }
    }
    return wires;
}

std::vector<TopoDS_Vertex> OCCUtils::ShapeComponents::AllVerticesWithin(const TopoDS_Shape& shape) {
    std::vector<TopoDS_Vertex> wires;
    for (TopExp_Explorer vertexExplorer(shape, TopAbs_VERTEX); vertexExplorer.More(); vertexExplorer.Next()) {
        const auto &vertex = TopoDS::Vertex(vertexExplorer.Current());
        if (vertex.IsNull()) {
            continue;
        }
        wires.push_back(vertex);
    }
    return wires;
}

std::vector<TopoDS_Vertex> OCCUtils::ShapeComponents::AllVerticesWithin(const std::vector<TopoDS_Shape>& shapes) {
    std::vector<TopoDS_Vertex> wires;
    for(const auto& shape : shapes) {
        for (TopExp_Explorer vertexExplorer(shape, TopAbs_VERTEX); vertexExplorer.More(); vertexExplorer.Next()) {
            const auto &vertex = TopoDS::Vertex(vertexExplorer.Current());
            if (vertex.IsNull()) {
                continue;
            }
            wires.push_back(vertex);
        }
    }
    return wires;

}

std::vector<gp_Pnt> OCCUtils::ShapeComponents::AllVertexCoordinatesWithin(const TopoDS_Shape& shape) {
    std::vector<gp_Pnt> vertices;
    for (TopExp_Explorer vertexExplorer(shape, TopAbs_VERTEX); vertexExplorer.More(); vertexExplorer.Next()) {
        const auto &vertex = TopoDS::Vertex(vertexExplorer.Current());
        if (vertex.IsNull()) {
            continue;
        }
        vertices.push_back(BRep_Tool::Pnt(vertex));
    }
    return vertices;
}

std::vector<gp_Pnt> OCCUtils::ShapeComponents::AllVertexCoordinatesWithin(const std::vector<TopoDS_Shape>& shapes) {
    std::vector<gp_Pnt> vertices;
    for(const auto& shape : shapes) {
        for (TopExp_Explorer vertexExplorer(shape, TopAbs_VERTEX); vertexExplorer.More(); vertexExplorer.Next()) {
            const auto &vertex = TopoDS::Vertex(vertexExplorer.Current());
            if (vertex.IsNull()) {
                continue;
            }
            vertices.push_back(BRep_Tool::Pnt(vertex));
        }
    }
    return vertices;

}

std::optional<TopoDS_Solid> OCCUtils::ShapeComponents::TryGetSingleSolid (const TopoDS_Shape& shape, bool firstOfMultipleOK) {
    // Is shape itself a solid?
    if(shape.ShapeType() == TopAbs_SOLID) {
        return TopoDS::Solid(shape);
    }
    // Else, expect there to be ONE sub-solid
    auto solids = ShapeComponents::AllSolidsWithin(shape);
    if(solids.empty()) {
        return std::nullopt;
    }
    if(solids.size() > 1 && !firstOfMultipleOK) {
        return std::nullopt;
    }
    return solids[0];
}

std::optional<TopoDS_Face> OCCUtils::ShapeComponents::TryGetSingleFace (const TopoDS_Shape& shape, bool firstOfMultipleOK) {
    // Is shape itself a solid?
    if(shape.ShapeType() == TopAbs_FACE) {
        return TopoDS::Face(shape);
    }
    // Else, expect there to be ONE sub-face
    auto faces = ShapeComponents::AllFacesWithin(shape);
    if(faces.empty()) {
        return std::nullopt;
    }
    if(faces.size() > 1 && !firstOfMultipleOK) {
        return std::nullopt;
    }
    return faces[0];
}

std::optional<TopoDS_Edge> OCCUtils::ShapeComponents::TryGetSingleEdge (const TopoDS_Shape& shape, bool firstOfMultipleOK) {
    // Is shape itself an edge?
    if(shape.ShapeType() == TopAbs_EDGE) {
        return TopoDS::Edge(shape);
    }
    // Else, expect there to be ONE sub-edge
    auto edges = ShapeComponents::AllEdgesWithin(shape);
    if(edges.empty()) {
        return std::nullopt;
    }
    if(edges.size() > 1 && !firstOfMultipleOK) {
        return std::nullopt;
    }
    return edges[0];
}

std::optional<TopoDS_Wire> OCCUtils::ShapeComponents::TryGetSingleWire (const TopoDS_Shape& shape, bool firstOfMultipleOK) {
    // Is shape itself a solid?
    if(shape.ShapeType() == TopAbs_WIRE) {
        return TopoDS::Wire(shape);
    }
    // Else, expect there to be ONE sub-wire
    auto wires = ShapeComponents::AllWiresWithin(shape);
    if(wires.empty()) {
        return std::nullopt;
    }
    if(wires.size() > 1 && !firstOfMultipleOK) {
        return std::nullopt;
    }
    return wires[0];
}

std::optional<TopoDS_Vertex> OCCUtils::ShapeComponents::TryGetSingleVertex (const TopoDS_Shape& shape, bool firstOfMultipleOK) {
    // Is shape itself a solid?
    if(shape.ShapeType() == TopAbs_VERTEX) {
        return TopoDS::Vertex(shape);
    }
    // Else, expect there to be ONE sub-vertex
    auto vertices = ShapeComponents::AllVerticesWithin(shape);
    if(vertices.empty()) {
        return std::nullopt;
    }
    if(vertices.size() > 1 && !firstOfMultipleOK) {
        return std::nullopt;
    }
    return vertices[0];
}

TopoDS_Solid OCCUtils::ShapeComponents::GetSingleSolid (const TopoDS_Shape& shape, bool firstOfMultipleOK) {
    auto opt = TryGetSingleSolid(shape, firstOfMultipleOK);
    if(!opt.has_value()) {
        throw new OCCTopologyCountMismatchException("Shape is not a solid and does not contain a single solid");
    }
    return opt.value();
}

TopoDS_Face OCCUtils::ShapeComponents::GetSingleFace (const TopoDS_Shape& shape, bool firstOfMultipleOK) {
    auto opt = TryGetSingleFace(shape, firstOfMultipleOK);
    if(!opt.has_value()) {
        throw new OCCTopologyCountMismatchException("Shape is not a face and does not contain a single face");
    }
    return opt.value();
}

TopoDS_Edge OCCUtils::ShapeComponents::GetSingleEdge (const TopoDS_Shape& shape, bool firstOfMultipleOK) {
    auto opt = TryGetSingleEdge(shape, firstOfMultipleOK);
    if(!opt.has_value()) {
        throw new OCCTopologyCountMismatchException("Shape is not a edge and does not contain a single edge");
    }
    return opt.value();
}

TopoDS_Wire OCCUtils::ShapeComponents::GetSingleWire (const TopoDS_Shape& shape, bool firstOfMultipleOK) {
    auto opt = TryGetSingleWire(shape, firstOfMultipleOK);
    if(!opt.has_value()) {
        throw new OCCTopologyCountMismatchException("Shape is not a wire and does not contain a single wire");
    }
    return opt.value();
}

TopoDS_Vertex OCCUtils::ShapeComponents::GetSingleVertex (const TopoDS_Shape& shape, bool firstOfMultipleOK) {
    auto opt = TryGetSingleVertex(shape, firstOfMultipleOK);
    if(!opt.has_value()) {
        throw new OCCTopologyCountMismatchException("Shape is not a vertex and does not contain a single vertex");
    }
    return opt.value();
}

size_t OCCUtils::ShapeComponents::CountX(const TopoDS_Shape& shape, TopAbs_ShapeEnum type) {
    size_t cnt = 0;
    for (TopExp_Explorer xExplorer(shape, type); xExplorer.More(); xExplorer.Next()) {
        cnt += xExplorer.Current().ShapeType() == type ? 1 : 0;
    }
    return cnt;
}

size_t OCCUtils::ShapeComponents::CountX(const std::vector<TopoDS_Shape>& shapes, TopAbs_ShapeEnum type) {
    size_t cnt = 0;
    for(const auto& shape: shapes) {
        cnt += CountX(shape, type);
    }
    return cnt;
}