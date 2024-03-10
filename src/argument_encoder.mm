namespace mtlpp {
    void setArgumentBuffer(mtlpp::Buffer buffer, int offset){

    }

    // Specifies an array element within a buffer where the encoder writes argument data. Required.
    void setArgumentBuffer(mtlpp::Buffer buffer, int startOffset, int arrayElement){

    }

    //Encoding Buffers
    // Encodes a reference to a buffer into the argument buffer. Required.
    void setBuffer(mtlpp::Buffer buffer, int offset, int index){

    }
    // Encodes references to an array of buffers into the argument buffer.
    void setBuffers(mtlpp::Buffer[] buffers, int[] offsets, Range<Int> range){

    }

    //Encoding Textures
    //Encodes a reference to a texture into the argument buffer. Required.
    void setTexture(mtlpp::Texture texture, int index){

    }
    // Encodes references to an array of textures into the argument buffer.
    void setTextures(mtlpp::Texture[] textures, Range<Int> range){

    }
    
    //Encoding Samplers
    //Encodes a sampler into the argument buffer. Required.
    void setSamplerState(mtlpp::SamplerState state, int index){

    }
    // Encodes an array of samplers into the argument buffer.
    void setSamplerStates(mtlpp::SamplerState[] states, Range<Int> range){

    }

    // Encoding Pipeline States
    // Encodes a reference to a render pipeline state into the argument buffer. Required.
    void setRenderPipelineState(mtlpp::RenderPipelineState renderState, int index){

    } //Encodes references to an array of render pipeline states into the argument buffer.

    void setRenderPipelineStates(mtlpp::RenderPipelineState  renderStates, Range<Int> range){

    }

    void setComputePipelineState(mtlpp::ComputePipelineState computeState, int index){

    } //Encodes a reference to a compute pipeline state into the argument buffer. Required.
    // void setComputePipelineStates(UnsafePointer<mtlpp::ComputePipelineState>, ns::Range with);  Encodes references to an array of compute pipeline states into the argument buffer.
    // Deprecated
    // void setComputePipelineState(mtlpp::ComputePipelineState computeState, int at);
    // Encodes a reference to a compute pipeline state into the argument buffer.
    // Deprecated
    void setComputePipelineStates(mtlpp::ComputePipelineState[] computeState, Range<Int> range){
    
    }//Encodes references to an array of compute pipeline states into the argument buffer.
    
    //Encoding Inlined Constant Data
    UnsafeMutableRawPointer constantData(int at);
    // Returns a pointer for an inlined constant data argument in the argument buffer.
    // Required.

    //Encoding Indirect Command Buffers
    void setIndirectCommandBuffer(mtlpp::IndirectCommandBuffer icb, int index){

    }
    // Encodes a reference to an indirect command buffer into the argument buffer.
    // Required.
    void setIndirectCommandBuffers(mtlpp::IndirectCommandBuffer[] icbs, Range<Int> range){

    }
    // Encodes an array of indirect command buffers into the argument buffer.

    // Encoding Acceleration Structures
    void setAccelerationStructure(mtlpp::AccelerationStructure?,  int index){

    }
    // Encodes a reference to an acceleration structure into the argument buffer.
    // Required.

    //Encoding Function Tables
    void setVisibleFunctionTable(mtlpp::VisibleFunctionTable?,    int index){

    }
    // Encodes a reference to a function table into the argument buffer.
    // Required.

    void setIntersectionFunctionTable(mtlpp::IntersectionFunctionTable table, int index){
        Validate();
        //[(__bridge id<MTLRenderCommandEncoder>)m_ptr   setVertexBufferOffset:offset       atIndex:index];
        [(__bridge MTLIntersectionFunctionTable*)m_ptr setIntersectionFunctionTable:table atIndex:index];
    }
    // Encodes a reference to a ray-tracing intersection function table into the argument buffer.
    // Required.

    void setIntersectionFunctionTables(mtlpp::IntersectionFunctionTable[] iTable, Range<int> range){
        Validate();
        return 
    }

    void setVisibleFunctionTables(mtlpp::VisibleFunctionTable[] vTable, Range<Int> range){
        Validate();
        return 
    }

    //Creating a Nested Argument Encoder
    ArgumentEncoder makeArgumentEncoderForBuffer(int atIndex){
        Validate();
        return 
    }
    // Creates a new argument encoder for a nested argument buffer.
    // Required.
}