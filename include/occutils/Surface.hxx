#pragma once
/**
 * Utilities for analyzing surfaces
 */
#include <gp_Ax1.hxx>
#include <gp_XY.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <vector>
#include <map>
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

        /**
         * Compute the normal of a surface at the given U/V coordinates.
         * @param surf The surface
         * @param u The U coordinate
         * @param v The V coordinate
         * @param precision Affects computation speed.
         * @returns The gp_Ax1 of the point on the surface described by U/V coords and the direction
         */
        gp_Ax1 Normal(const GeomAdaptor_Surface& surf, double u = 0.0, double v = 0.0, double precision=1e-6);
        gp_Ax1 Normal(const GeomAdaptor_Surface& surf, const gp_Pnt2d& uv, double precision=1e-6);
        gp_Ax1 Normal(const GeomAdaptor_Surface& surf, const gp_XY& uv, double precision=1e-6);

        /**
         * Compute the normal direction of a surface at the given U/V coordinates.
         * @param surf The surface
         * @param u The U coordinate
         * @param v The V coordinate
         * @param precision Affects computation speed.
         */
        gp_Dir NormalDirection(const GeomAdaptor_Surface& surf, double u = 0.0, double v = 0.0, double precision=1e-6);


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

        /**
         * Sample the point on the given surface at the given U/V coordinates.
         * The point represents the 0th derivative.
         */
        gp_Pnt PointAt(const GeomAdaptor_Surface& surf, double u = 0.0, double v = 0.0);
        /**
         * Sample the point on the given surface at the given U/V coordinates.
         * The X coord of the gp_Pnt2d is interpreted as U whereas the Y coord of the gp_Pnt2d
         * is interpreted as V.
         * The point represents the 0th derivative.
         */
        gp_Pnt PointAt(const GeomAdaptor_Surface& surf, const gp_Pnt2d& uv);
        /**
         * Sample the point on the given surface at the given U/V coordinates.
         * The X coord of the gp_XY is interpreted as U whereas the Y coord of the gp_XY
         * is interpreted as V.
         * The point represents the 0th derivative.
         */
        gp_Pnt PointAt(const GeomAdaptor_Surface& surf, const gp_XY& uv);

        /**
         * Given a surface, creates a NxM uniformly spaces U/V grid between Umin/Umax and Vmin/Vmax.
         * Umin/Umax and Vmin/Umax are included and represent the first/last sample point.
         * The returned gp_XY coordinates shall be interpreted as U/V coordinates!
         */
        std::vector<gp_XY> UniformUVSampleLocations(
            const GeomAdaptor_Surface& surf, size_t uSamples=10, size_t vSamples=10);

        /**
         * Like UniformUVSampleLocations(), but computes sample points within the limits,
         * not including the U/V limits.
         * Equivalent to calling UniformUVSampleLocations() with 2 more samples in each direction
         */
        std::vector<gp_XY> UniformUVSampleLocationsWithin(
            const GeomAdaptor_Surface& surf, size_t uSamples=10, size_t vSamples=10);


        //TODO These are not implemented yet!
        /**
         * Sample the slope on the given surface at the given U/V coordinates.
         * The slope represents the 1st derivative.
         */
        //gp_Pnt SlopeAt(const GeomAdaptor_Surface& surf, double u = 0.0, double v = 0.0);
        /**
         * Sample the curvature on the given surface at the given U/V coordinates.
         * The curvature represents the 2nd derivative.
         */
        //gp_Pnt CurvatureAt(const GeomAdaptor_Surface& surf, double u = 0.0, double v = 0.0);
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
        std::vector<SurfaceInfo> Only(const std::vector<SurfaceInfo>& surfaces,
            GeomAbs_SurfaceType type);

        /**
         * Filter surfaces by a custom filter function
         */
        std::vector<SurfaceInfo> Filter(const std::vector<SurfaceInfo>& surfaces,
            const std::function<bool(const GeomAdaptor_Surface& surf)>& filt);


        struct SurfaceTypeStats {
            void Add(GeomAbs_SurfaceType typ, size_t cnt = 1);
            size_t Count(GeomAbs_SurfaceType typ);
            // Get a human-readable summary of the stats
            std::string Summary();
            // Counts how many time
            std::map<GeomAbs_SurfaceType, size_t> count;
        };

        SurfaceTypeStats Statistics(const std::vector<SurfaceInfo>& surfaces);

    }
}