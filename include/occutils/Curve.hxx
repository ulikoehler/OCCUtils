#pragma once
#include <GeomAdaptor_Curve.hxx>
#include <Geom_Curve.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <TopoDS_Edge.hxx>
#include <functional>

namespace OCCUtils {
    namespace Curve {
        /**
         * Get a curve from the given edge.
         * If it fails, returnValue.Curve().IsNull() == true
         */
        GeomAdaptor_Curve FromEdge(const TopoDS_Edge& edge);

        /**
         * Convert a trimmed curve to a GeomAdapter_Curve
         */
        GeomAdaptor_Curve FromTrimmedCurve(const Geom_TrimmedCurve &curve);

        /**
         * Length of a curve (by adaptor)
         */
        double Length(const GeomAdaptor_Curve& curve);
        /**
         * Length of a curve (by curve handle).
         * Note that many Geom_Curve subclasses describe infinite
         * curves and Geom_Curve does not have the correct trimming
         * parameters by itself. Use GeomAdaptor_Curve or
         * Geom_TrimmedCurve instead.
         */
        double Length(const Handle(Geom_Curve)& curve);
        /**
         * Length of a curve (by curve handle)
         */
        double Length(const Geom_TrimmedCurve &curve);

        bool IsLine(const GeomAdaptor_Curve& curve);
        bool IsCircle(const GeomAdaptor_Curve& curve);
        bool IsEllipse(const GeomAdaptor_Curve& curve);
        bool IsHyperbola(const GeomAdaptor_Curve& curve);
        bool IsParabola(const GeomAdaptor_Curve& curve);
        bool IsBezier(const GeomAdaptor_Curve& curve);
        bool IsBSpline(const GeomAdaptor_Curve& curve);
        bool IsOffsetCurve(const GeomAdaptor_Curve& curve);
        bool IsOther(const GeomAdaptor_Curve& curve);
    }
    namespace Curves {
        /**
         * Filter a list of curves: Get only curves that match the given type
         */
        std::vector<GeomAdaptor_Curve> Only(const std::vector<GeomAdaptor_Curve>& curves,
            GeomAbs_CurveType type);

        /**
         * Filter a list of curves: Get only curves for which the given predicate returns true
         */
        std::vector<GeomAdaptor_Curve> Filter(const std::vector<GeomAdaptor_Curve>& curves,
            std::function<bool(const GeomAdaptor_Curve& curve)> predicate);
    }
}