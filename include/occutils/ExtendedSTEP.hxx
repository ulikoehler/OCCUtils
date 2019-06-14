#pragma once
#include <memory>

#include <Quantity_Color.hxx>
#include <TopoDS_Shape.hxx>
#include <XCAFDoc_ColorType.hxx>

namespace OCCUtils {
    namespace STEP {
        /**
         * Hidden internal state for the extended STEP exporter.
         */
        struct _ExtendedSTEPExporterInternals;
        /**
         * Extended STEP Exporter that allows you to use:
         *  - Colors
         *  - Materials
         *  - etc
         */
        class ExtendedSTEPExporter {
            public:
                ExtendedSTEPExporter();
                ~ExtendedSTEPExporter();
                /**
                 * Add a shape without any special attributes
                 * @return The internal ID for this shape. Can be used to refer to it later.
                 * Usually you can ignore this.
                 */
                size_t AddShape(TopoDS_Shape& shape);
                size_t AddShapeWithColor(TopoDS_Shape& shape, const Quantity_Color& color, XCAFDoc_ColorType colorType = XCAFDoc_ColorGen );
                /**
                 * Write the data from this STEP exporter to
                 * the given STEP file
                 */
                void Write(const std::string& filename);
            private:
                _ExtendedSTEPExporterInternals* internals;

        };
    }
}