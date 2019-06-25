#pragma once
/**
 * Utilities for analyzing surfaces
 */
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <vector>
#include <functional>

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
         * If no surface can be found, returnValue.Surface().IsNull() == true
         */
        GeomAdaptor_Surface FromFace(const TopoDS_Face& face);
        /**
         * Get both the area and the center of mass of a surface.
         * This is more efficient than computing them individually.
         */
        std::pair<double, gp_Pnt> AreaAndCenterOfMass(const TopoDS_Shape& face);

        bool IsPlane(const GeomAdaptor_Surface& surf);
        bool IsCylinder(const GeomAdaptor_Surface& surf);
        bool IsCone(const GeomAdaptor_Surface& surf);
        bool IsSphere(const GeomAdaptor_Surface& surf);
        bool IsTorus(const GeomAdaptor_Surface& surf);
        bool IsBezierSurface(const GeomAdaptor_Surface& surf);
        bool IsBSplineSurface(const GeomAdaptor_Surface& surf);
        bool IsSurfaceOfRevolution(const GeomAdaptor_Surface& surf);
        bool IsSurfaceOfExtrusion(const GeomAdaptor_Surface& surf);
        bool IsOffsetSurface(const GeomAdaptor_Surface& surf);
        bool IsOtherSurface(const GeomAdaptor_Surface& surf);
    }
    namespace Surfaces {
        struct SurfaceInfo {
            TopoDS_Face face;
            GeomAdaptor_Surface surface;
        };
        /**
         * Get all faces & their surfaces that are within shape.
         * Uses ShapeComponents::AllFacesWithin(shape) internally.
         * Does not return surfaces that have no surface   
         */
        std::vector<SurfaceInfo> FromShape(const TopoDS_Shape& shape);

        /**
         * Filter surfaces by type
         */
        std::vector<SurfaceInfo> Filter(const std::vector<SurfaceInfo>& surfaces,
            GeomAbs_SurfaceType type);

        /**
         * Filter surfaces by a custom filter function
         */
        std::vector<SurfaceInfo> Filter(const std::vector<SurfaceInfo>& surfaces,
            const std::function<bool(const GeomAdaptor_Surface& surf)>& filt);
    }
}