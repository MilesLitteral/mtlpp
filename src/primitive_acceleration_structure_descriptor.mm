
#include <Metal/MTLPrimitiveAccelerationStructureDescriptor.h>
namespace mtlpp {
    Overview
    Metal provides acceleration structures with a two-level hierarchy. The bottom layer consists of primitive acceleration structures, which instance acceleration structures in the top level reference.

    Topics
    Specifying Geometry
    var geometryDescriptors: [mtlpp::AccelerationStructureGeometryDescriptor]?
    An array that contains the individual pieces of geometry that compose the acceleration structure.
    Specifying Motion Behavior
    var motionKeyframeCount: Int
    The number of keyframes in the geometry data.
    var motionStartTime: Float
    The start time for the range of motion that the keyframe data describes.
    var motionEndTime: Float
    The end time for the range of motion that the keyframe data describes.
    var motionStartBorderMode: mtlpp::MotionBorderMode
    The mode to use when handling timestamps before the start time.
    var motionEndBorderMode: mtlpp::MotionBorderMode
    The mode to use when handling timestamps after the end time.
    enum MTLMotionBorderMode
    Options for specifying how the acceleration structure handles timestamps that are outside the specified range.
    Relationships
    Inherits From
    MTLAccelerationStructureDescriptor
}