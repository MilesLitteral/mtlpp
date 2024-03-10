#include "ns.hpp"

namespace mtlpp {
    class IndirectComputeCommand : ns::Object {
        //Overview
        //Don’t implement this protocol; you get objects of this type by asking a MTLIndirectCommandBuffer for them.
        //Use this object to reset or encode a command. You must always reset a command before encoding a new command.

        //Topics
        //Setting a Command's Arguments
        void setComputePipelineState(mtlpp::ComputePipelineState state);
        // Sets the command’s compute pipeline state object.
        // Required.

        void setImageblockWidth(int, int height);
        // Sets the size, in pixels, of the imageblock.
        // Required.

        void setKernelBuffer(mtlpp::Buffer, int offset, int at);
        // Sets a buffer for the compute function.
        // Required.

        void setThreadgroupMemoryLength(int, int index);
        // Sets the size of a block of threadgroup memory.
        // Required.

        void setStageInRegion(mtlpp::Region);
        // Sets the region of the stage-in attributes to apply to the compute kernel.
        // Required.

        // Synchronizing Command Execution
        void setBarrier();
        // Adds a barrier to ensure that commands executed prior to this command are complete before this command executes.
        // Required.

        void clearBarrier();
        // Removes any barrier set on the command.
        // Required.

        // Encoding a Compute Command
        void concurrentDispatchThreadgroups(mtlpp::Size, mtlpp::Size threadsPerThreadgroup);
        // Encodes a compute command using a grid aligned to threadgroup boundaries.
        // Required.

        void concurrentDispatchThreads(mtlpp::Size,      mtlpp::Size threadsPerThreadgroup);
        // Encodes a compute command using an arbitrarily sized grid.
        // Required.

        // Resetting a Command
        void reset();
        // Resets the command to its default state.
        // Required.
    }
}