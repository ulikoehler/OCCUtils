#include "occutils/Compound.hxx"
#include "occutils/ListUtils.hxx"
#include "occutils/Shape.hxx"
#include <BRep_Builder.hxx>

using namespace OCCUtils;


template <typename T>
TopoDS_Compound _ToCompound(const T& shapes) {
    BRep_Builder builder;
    TopoDS_Compound compound;
    builder.MakeCompound (compound);
    for (const auto& shape : shapes) {
        if (!shape.IsNull()) {
            builder.Add (compound, shape);
        }
    }
    return compound;
}

TopoDS_Compound OCCUtils::Compound::From(const TopTools_ListOfShape& shapes) {
    return _ToCompound(shapes);
}

TopoDS_Compound OCCUtils::Compound::From(const std::vector<TopoDS_Shape>& shapes) {
    return _ToCompound(shapes);
}

TopoDS_Compound OCCUtils::Compound::From(const std::vector<TopoDS_Face>& shapes) {
    return _ToCompound(shapes);
}

TopoDS_Compound OCCUtils::Compound::From(const std::vector<TopoDS_Solid>& shapes) {
    return _ToCompound(shapes);
}
