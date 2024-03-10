#include "ns.hpp"
#include "device.hpp"
#include <Metal/MTLIndirectCommandBuffer.h>

namespace mtlpp
{
    //Retrieving Commands
    //Gets the render command at the given index. Required.
    mtlpp::IndirectRenderCommand IndirectCommandBuffer::indirectRenderCommandAt(int renderCommandAt){
        Validate();
        [(__bridge id<MTLIndirectRenderCommand>)m_ptr indirectRenderCommandAt:(__bridge id<int>)renderCommandAt.GetPtr()];
    }

    // Gets the compute command at the given index. Required.
    mtlpp::IndirectComputeCommand IndirectCommandBuffer::indirectComputeCommandAt(int computeCommandAt){
        Validate();
        [(__bridge id<MTLIndirectRenderCommand>)m_ptr indirectComputeCommandAt:(__bridge id<int>)computeCommandAt.GetPtr()];
    } 

    //Resets a range of commands to their default state.
    void IndirectCommandBuffer::reset(Range<Int> r){
        Validate();
        [(__bridge id<MTLIndirectRenderCommand>)m_ptr reset:(__bridge id<Range<Int>>)r.GetPtr()];
    }
}