#pragma once
/**
 * Utilities for analyzing surfaces
 */
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <optional>

namespace OCCUtils {
    namespace Surface {
        /**
         * Get the center of mass of a surface.
         * This isn't neccessarily on the surface itself.
         */
        gp_Pnt CenterOfMass(const TopoDS_Shape& face);
        /**
         * Get the total surface area of a face, solid etc.
         */
        double Area(const TopoDS_Shape& face);
        /**
         * Get the 3D surface from a given face
         */
        std::optional<GeomAdaptor_Surface> FromFace(const TopoDS_Face& face);
        /**
         * Get both the area and the center of mass of a surface.
         * This is more efficient than computing them individually.
         */
        std::pair<double, gp_Pnt> AreaAndCenterOfMass(const TopoDS_Shape& face);
    }
}