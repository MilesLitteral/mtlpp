namespace mtlpp {
    class AccelerationStructureBoundingBoxGeometryDescriptor : mtlpp::AccelerationStructureGeometryDescriptor {
        int boundingBoxBufferOffset; //The offset, in bytes, to the first bounding box in the buffer.
        int boundingBoxStride;       //The stride, in bytes, between bounding boxes in the buffer.
        int boundingBoxCount;        //The number of bounding boxes in the bounding box buffer.

        //Specifying Bounding Boxes Data
        mtlpp::Buffer boundingBoxBuffer; //A buffer that contains bounding box data.
    }
}