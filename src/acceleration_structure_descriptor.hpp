#include "ns.hpp"

namespace mtlpp {
    class AccelerationStructureDescriptor : ns::Object {
        //Overview
        //This is the base class for other acceleration structure descriptors. Don’t use this class directly. Use one of the derived classes instead, as MTLAccelerationStructure describes.

        //Topics
        //Specifying Usage Options
        mtlpp::AccelerationStructureUsage usage; //: MTLAccelerationStructureUsage
        //The options that describe how you intend to use the acceleration structure.
    }
}