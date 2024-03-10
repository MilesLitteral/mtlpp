#include "mtlpp.hpp"
#include <Metal/MTLIndirectRenderCommand.h>

namespace mtlpp {
    // Overview
    // Don’t implement this protocol; you get objects of this type by asking a MTLIndirectCommandBuffer for them.
    // Use this object to reset or encode a command. You must always reset a command before encoding a new command.

    // Topics
    // Setting Command Arguments
    void IndirectRenderCommand::setRenderPipelineState(mtlpp::RenderPipelineState){

    }
    // Sets the render pipeline state object used by the command.
    // Required.

    void IndirectRenderCommand:;setVertexBuffer(mtlpp::Buffer buffer, int offset, int at){

    }
    // Sets a vertex buffer argument for the command.
    // Required.

    void IndirectRenderCommand::setFragmentBuffer(mtlpp::Buffer buffer, int offset, int at){

    }
    // Sets a fragment buffer argument for the command.
    // Required.

    // Encoding a Drawing Command
    void IndirectRenderCommand::drawPrimitives(mtlpp::PrimitiveType, vertexStart: Int, vertexCount: Int, instanceCount: Int, baseInstance: Int){

    }

    // Encodes a command to render a number of instances of primitives using vertex data in contiguous array elements, starting from the base instance.
    // Required.

    void IndirectRenderCommand::drawIndexedPrimitives(mtlpp::PrimitiveType, indexCount: Int, indexType: mtlpp::IndexType, indexBuffer: MTLBuffer, indexBufferOffset: Int, instanceCount: Int, baseVertex: Int, baseInstance: Int){

    }
    // Encodes a command to render a number of instances of primitives using an index list specified in a buffer, starting from the base vertex of the base instance.
    // Required.

    void IndirectRenderCommand::drawPatches(Int, patchStart: Int, patchCount: Int, patchIndexBuffer: mtlpp::Buffer?, patchIndexBufferOffset: Int, instanceCount: Int, baseInstance: Int, tessellationFactorBuffer: mtlpp::Buffer, tessellationFactorBufferOffset: Int, tessellationFactorBufferInstanceStride: Int){

    }
    // Encodes a command to render a number of instances of tessellated patches.
    // Required.

    void IndirectRenderCommand::drawIndexedPatches(Int, patchStart: Int, patchCount: Int, patchIndexBuffer: mtlpp::Buffer?, patchIndexBufferOffset: Int, controlPointIndexBuffer: mtlpp::Buffer, controlPointIndexBufferOffset: Int, instanceCount: Int, baseInstance: Int, tessellationFactorBuffer: mtlpp::Buffer, tessellationFactorBufferOffset: Int, tessellationFactorBufferInstanceStride: Int){

    }
    // Encodes a command to render a number of instances of tessellated patches, using a control point index buffer.
    // Required.

    // Resetting a Command
    void IndirectRenderCommand::reset(){

    }
    // Resets the command to its default state.
    // Required.
}