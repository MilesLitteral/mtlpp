namespace mtlpp {
    void setComputePipelineState(mtlpp::ComputePipelineState state){
        [(__bridge id<MTLComputePipelineState>)m_ptr
            setComputePipelineState:(__bridge id<MTLTexture>)texture.GetPtr()
            state:width
        ]
    };

    void setImageblockWidth(int width){
        [(__bridge id<MTLComputePipelineState>)m_ptr
            setImageblockWidth:(__bridge id<MTLTexture>)texture.GetPtr()
            width:width
        ]
    };

    void setKernelBuffer(mtlpp::Buffer, int offset, int at){

    };
    
    void setThreadgroupMemoryLength(int index){

    };

    void setStageInRegion(mtlpp::Region){

    };

    void setStageIn(mtlpp::Region){

    };

    void setBarrier(){

    };

    void clearBarrier(){

    };

    void concurrentDispatchThreadgroups(mtlpp::Size, threadsPerThreadgroup: mtlpp::Size){

    };

    void concurrentDispatchThreads(mtlpp::Size,      threadsPerThreadgroup: mtlpp::Size){

    };

    void reset(){

    };
}