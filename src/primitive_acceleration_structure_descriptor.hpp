#include "acceleration_structure_descriptor.hpp"

namespace mtlpp{
    class PrimitiveAccelerationStructureDescriptor : mtlpp::AccelerationStructureDescriptor {
        //Overview
        //Metal provides acceleration structures with a two-level hierarchy. The bottom layer consists of primitive acceleration structures, which instance acceleration structures in the top level reference.

        //Topics
        //Specifying Geometry
        mtlpp::AccelerationStructureGeometryDescriptor[] geometryDescriptors;
        //An array that contains the individual pieces of geometry that compose the acceleration structure.
        //Specifying Motion Behavior
        int motionKeyframeCount;
        //The number of keyframes in the geometry data.
        float motionStartTime;
        //The start time for the range of motion that the keyframe data describes.
        float motionEndTime;
        //The end time for the range of motion that the keyframe data describes.
        mtlpp::MotionBorderMode motionStartBorderMode;
        //The mode to use when handling timestamps before the start time.
        mtlpp::MotionBorderMode motionEndBorderMode;
        //The mode to use when handling timestamps after the end time.
    }
}