#include "resource.hpp"
namespace mtlpp {
    class AccelerationStructure : mtlpp::Resource {
        // Overview
        // To accelerate ray tracing, the device object needs to reorganize your model data into an optimized data structure for intersection testing on that GPU. Create MTLAccelerationStructure objects to contain your model data and reference them in compute and render commands that execute ray-tracing operations.
        // You don’t define classes that implement this protocol. To create an acceleration structure, you create a descriptor object and configure its properties with your model data. Then call the makeAccelerationStructure(descriptor:) method on the Metal device object to create the object and reserve memory for the structure. To populate the structure with the data, use a MTLAccelerationStructureCommandEncoder to encode GPU commands.
        // Metal provides multiple descriptor classes, each describing a different type of model data. Choose the appropriate descriptor for each acceleration structure you want to make. Most often, you create an acceleration structure for each list of triangles or bounding boxes. Then collect related geometry structures into a primitive acceleration structure. Create instance acceleration structures when you need to reference instances of primitive acceleration structures at different locations within a scene.
        int size;
        mtlpp::ResourceID gpuResourceID;

        //Descriptor classes
        mtlpp::AccelerationStructureTriangleGeometryDescriptor triangleGeometryDesc;

        //Describes an acceleration structure for a list of triangles.
        mtlpp::AccelerationStructureBoundingBoxGeometryDescriptor boxGeometryDesc;

        //Describes an acceleration structure for a list of bounding boxes.
        mtlpp::PrimitiveAccelerationStructureDescriptor primAccelerationDesc;

        //Describes an acceleration structure for a list of bounding-box or triangle acceleration structures, effectively creating a union of all of the underlying geometry.
        mtlpp::InstanceAccelerationStructureDescriptor  instAccelerationDesc;
    }
}