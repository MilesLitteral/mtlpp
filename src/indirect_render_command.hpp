namespace mtlpp {
    class IndirectRenderCommand : ns::Object {
        // Overview
        // Don’t implement this protocol; you get objects of this type by asking a MTLIndirectCommandBuffer for them.
        // Use this object to reset or encode a command. You must always reset a command before encoding a new command.
        public:
        //Topics
        //Setting Command Arguments
        void setRenderPipelineState(mtlpp::RenderPipelineState state);
        //Sets the render pipeline state object used by the command.
        //Required.
        void setVertexBuffer(mtlpp::Buffer   buffer, int offset, int at);
        //Sets a vertex buffer argument for the command.
        //Required.
        void setFragmentBuffer(mtlpp::Buffer buffer, int offset, int at);
        // Sets a fragment buffer argument for the command.
        // Required.

        // Encoding a Drawing Command
        void drawPrimitives(mtlpp::PrimitiveType, int vertexStart, int vertexCount, int instanceCount, int baseInstance);
        // Encodes a command to render a number of instances of primitives using vertex data in contiguous array elements, starting from the base instance.
        // Required.

        void drawIndexedPrimitives(mtlpp::PrimitiveType, int indexCount, mtlpp::IndexType indexType, mtlpp::Buffer indexBuffer, int indexBufferOffset, int instanceCount, int baseVertex, int baseInstance);
        // Encodes a command to render a number of instances of primitives using an index list specified in a buffer, starting from the base vertex of the base instance.
        // Required.

        void drawPatches(int numOfInstances, int patchStart, int patchCount, mtlpp::Buffer patchIndexBuffer, int patchIndexBufferOffset, int instanceCount, int baseInstance, mtlpp::Buffer tessellationFactorBuffer, int tessellationFactorBufferOffset, int tessellationFactorBufferInstanceStride);
        // Encodes a command to render a number of instances of tessellated patches.
        // Required.

        void drawIndexedPatches(int numOfPatches, int patchStart, int patchCount, mtlpp::Buffer patchIndexBuffer, int patchIndexBufferOffset, mtlpp::Buffer controlPointIndexBuffer, int controlPointIndexBufferOffset, int instanceCount, int baseInstance, mtlpp::Buffer tessellationFactorBuffer, int tessellationFactorBufferOffset, int tessellationFactorBufferInstanceStride);
        // Encodes a command to render a number of instances of tessellated patches, using a control point index buffer.
        // Required.

        //Resetting a Command
        void reset();
        // Resets the command to its default state.
        // Required.
    };
}