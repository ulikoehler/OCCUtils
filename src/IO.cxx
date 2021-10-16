#include "occutils/IO.hxx"
#include "occutils/Exceptions.hxx"

#include <STEPControl_Reader.hxx>
#include <IGESControl_Reader.hxx>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost::algorithm;

std::shared_ptr<XSControl_Reader> OCCUtils::IO::Reader::STEPorIGESReader(const std::string& filename) {
    shared_ptr<XSControl_Reader> reader;
    // Automatically determine filename
    string lowercaseFilename = to_lower_copy(filename);
    if (ends_with(lowercaseFilename, ".step") || ends_with(lowercaseFilename, ".stp")) {
        reader = shared_ptr<XSControl_Reader>(dynamic_cast<XSControl_Reader*>(new STEPControl_Reader()));
    } else if (ends_with(lowercaseFilename, ".iges") || ends_with(lowercaseFilename, ".igs")) {
        reader = shared_ptr<XSControl_Reader>(dynamic_cast<XSControl_Reader*>(new IGESControl_Reader()));
    } else {
        throw OCCIOException("Unknown file extension (.stp/.step or .igs/.iges expected): " + filename);
    }
    return reader;
}

std::shared_ptr<XSControl_Reader> OCCUtils::IO::Reader::STEPReader() {
    return shared_ptr<XSControl_Reader>(dynamic_cast<XSControl_Reader*>(new STEPControl_Reader()));
}

std::shared_ptr<XSControl_Reader> OCCUtils::IO::Reader::IGESReader() {
    return shared_ptr<XSControl_Reader>(dynamic_cast<XSControl_Reader*>(new IGESControl_Reader()));
}

/**
 * Convert a IFSelect_ReturnStatus code to string
 */
static std::string _IFSelectReturnStatusToString(IFSelect_ReturnStatus code) {
    switch (code) {
    case IFSelect_RetVoid: return "Void";
    case IFSelect_RetDone: return "Done";
    case IFSelect_RetError: return "Error";
    case IFSelect_RetFail: return "Fail";
    case IFSelect_RetStop: return "Stop";
    default: return "Unknown";
    }
}

void OCCUtils::IO::Reader::ReadFile(const std::shared_ptr<XSControl_Reader>& reader, const std::string& filename) {
    auto readStat = reader->ReadFile(filename.c_str());
    if (readStat != IFSelect_ReturnStatus::IFSelect_RetDone) {
        throw OCCIOException("Failed to read file, error code: " + _IFSelectReturnStatusToString(readStat));
    }
}

TopoDS_Shape OCCUtils::IO::Reader::ReadOneShape(const std::shared_ptr<XSControl_Reader>& reader) {
    // Check if there is anything to convert
    auto numroots = reader->NbRootsForTransfer();
    if (numroots < 1) {
        throw OCCIOException("Failed to read file: No roots to transfer are present");
    }
    // Convert STEP to shape
    if (reader->TransferRoots() < 1) {
        throw OCCIOException("Failed to read file: Failed to transfer any roots");
    }
    return reader->OneShape();
}

TopoDS_Shape OCCUtils::IO::Read(const std::string& filename) {
    auto reader = IO::Reader::STEPorIGESReader(filename);
    IO::Reader::ReadFile(reader, filename);
    return IO::Reader::ReadOneShape(reader);
}