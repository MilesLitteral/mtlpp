namespace mtlpp {
    class AccelerationStructureTriangleGeometryDescriptor : MTLAccelerationStructureGeometryDescriptor {
        //Topics
        //Specifying the Number of Triangles
        int triangleCount;
        //The number of triangles in the buffers.
        //The data type of indices in the index buffer.
        int indexBufferOffset;
        //The offset, in bytes, to the first index in the buffer.
        //Specifying Index Data
        mtlpp::Buffer    indexBuffer;
        //A buffer that contains indices for the vertices that compose the triangle list.
        mtlpp::IndexType indexType;
        //Specifying Vertex Data
        mtlpp::Buffer    vertexBuffer;
        //A buffer that contains vertex data.
        int vertexBufferOffset;
        //The offset, in bytes, for the first vertex in the vertex buffer.
        int vertexStride;
        //The stride, in bytes, between vertices in the vertex buffer.
        //Instance Properties
        int    transformationMatrixBufferOffset;
        mtlpp::Buffer transformationMatrixBuffer;
        mtlpp::AttributeFormat vertexFormat;
    };
}