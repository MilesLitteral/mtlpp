
#include <Metal/MTLPrimitiveAccelerationStructureDescriptor.h>
namespace mtlpp {
        //Overview
        //Metal provides acceleration structures with a two-level hierarchy. The bottom layer consists of primitive acceleration structures, which instance acceleration structures in the top level reference.
        class PrimitiveAccelerationStructureDescriptor : mtlpp::AccelerationStructureDescriptor {
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
        mtlpp::MotionBorderMode motionStartBorderMode
        //The mode to use when handling timestamps before the start time.
        //var motionEndBorderMode: mtlpp::MotionBorderMode
        //The mode to use when handling timestamps after the end time.
        enum LMotionBorderMode {

        }
        //Options for specifying how the acceleration structure handles timestamps that are outside the specified range.
        //Relationships
        //Inherits From
        //MTLAccelerationStructureDescriptor
    }
}