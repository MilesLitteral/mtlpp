namespace mtlpp {
    class AccelerationStructureBoundingBoxGeometryDescriptor : mtlpp::AccelerationStructureGeometryDescriptor {
        // Topics
        // Specifying the Number of Bounding Boxes
        int boundingBoxCount;
        // The number of bounding boxes in the bounding box buffer.
        // Specifying Bounding Boxes Data
        mtlpp::Buffer boundingBoxBuffer;
        // A buffer that contains bounding box data.
        int boundingBoxBufferOffset;
        // The offset, in bytes, to the first bounding box in the buffer.
        int boundingBoxStride;

        AccelerationStructureBoundingBoxGeometryDescriptor(int count, mtlpp::Buffer buffer, int boundingOffset, int boundingStride){
            boundingBoxCount =count;
        // The number of bounding boxes in the bounding box buffer.
        // Specifying Bounding Boxes Data
            boundingBoxBuffer = buffer;
        // A buffer that contains bounding box data.
            boundingBoxBufferOffset = boundingOffset;
        // The offset, in bytes, to the first bounding box in the buffer.
            boundingBoxStride = boundingStride;
        }
    }
}
