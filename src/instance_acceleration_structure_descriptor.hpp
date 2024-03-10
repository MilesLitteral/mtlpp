namespace mtlpp {
    class InstanceAccelerationStructureDescriptor : mtlpp::AccelerationStructureDescriptor {
        // Overview
        // Metal provides acceleration structures with a two-level hierarchy. The bottom layer consists of primitive acceleration structures, which instance acceleration structures in the top level reference.

        //Topics
        //Specifying the Instance Structures
        mtlpp::AccelerationStructureInstanceDescriptorType instanceDescriptorType;
        //The format of the instance data in the descriptor buffer.

        mtlpp::AccelerationStructure[] instancedAccelerationStructures;
        // The bottom-level acceleration structures that instances use in the instance acceleration structure.

        enum mtlpp::AccelerationStructureInstanceDescriptorType {
            defaultCharactistics,   // An option Specifying that the instance uses the default characteristics.
            userID,    // An option specifying that the instance contains a user identifier.
            motion     // An option specifying that the instance contains motion data.
        };

        //Options for specifying different kinds of instance types.
        //Specifying the List of Instances
        int instanceCount;
        //The number of instances in the instance descriptor buffer.

        mtlpp::Buffer instanceDescriptorBuffer;
        //A buffer that contains descriptions of each instance in the acceleration structure.

        int instanceDescriptorBufferOffset;
        //The offset, in bytes, to the descripton of the first instance.

        int instanceDescriptorStride;
        //The stride, in bytes, between instance descriptions.
        //Specifying Motion Data

        int motionTransformCount;
        //The number of motion transforms in the motion transform buffer.
        //var motionTransformBuffer: MTLBuffer?
        //A buffer that contains descriptions of each motion transform in the acceleration structure.

        int motionTransformBufferOffset;
        //The offset, in bytes, to the descripton of the first motion transform.
    };
}