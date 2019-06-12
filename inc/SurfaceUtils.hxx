#pragma once
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <optional>

namespace OCCUtil {
    namespace SurfaceUtils {
        /**
         * Get the total surface area of a face, solid etc.
         */
        double SurfaceArea(const TopoDS_Shape& face);
        /**
         * Get the 3D surface from a given face
         */
        std::optional<GeomAdaptor_Surface> SurfaceFromFace(const TopoDS_Face& face);

    }
}