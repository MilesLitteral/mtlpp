// MTLAccelerationStructureGeometryDescriptor : ns::Object
// A base class for descriptors that contain geometry data to convert into a ray-tracing acceleration structure.
// iOS 14.0+
// iPadOS 14.0+
// macOS 11.0+
// Mac Catalyst 14.0+
// tvOS 16.0+
// Declaration
#include "ns.hpp"

namespace mtlpp {
    class AccelerationStructureGeometryDescriptor : ns::Object {
        // Overview
        // Don’t use this base class directly. Use one of the derived classes instead, as MTLAccelerationStructure describes.

        // Topics
        //Specifying Base Geometry Properties
        ns::String AccelerationStructureGeometryDescriptor::label;
        //A label for the geometry structure, suitable for debugging.
        int AccelerationStructureGeometryDescriptor::intersectionFunctionTableOffset;
        //An index into the intersection table for determining which intersection function Metal calls when it intersects a ray with the acceleration structure.
        bool AccelerationStructureGeometryDescriptor::opaque;
        //A Boolean value that determines whether the geometry data in the acceleration structure needs to skip triangle-intersection tests.
        bool AccelerationStructureGeometryDescriptor::allowDuplicateIntersectionFunctionInvocation;
        // A Boolean value that indicates whether Metal calls the ray-intersection test more than once per primitive on the structure.
        // Instance Properties
        mtlpp::Buffer AccelerationStructureGeometryDescriptor::primitiveDataBuffer;
        int AccelerationStructureGeometryDescriptor::primitiveDataBufferOffset;
        int AccelerationStructureGeometryDescriptor::primitiveDataElementSize;
        int AccelerationStructureGeometryDescriptor::primitiveDataStride;
    }
}