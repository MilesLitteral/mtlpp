#include "ns.hpp"
#include "defines.hpp"

namespace mtlpp {
    class IndirectCommandBufferDescriptor : ns::Object {
        // A Boolean value that determines where commands in the indirect command buffer get their buffer arguments from when you execute them.
        bool inheritBuffers;
        bool inheritPipelineState;

        // A Boolean value that determines where commands in the indirect command buffer get their pipeline state from when you execute them.
        // Declaring the Maximum Number of Argument Buffers Per Command
        int maxVertexBufferBindCount;

        //The maximum number of buffers that you can set per command for the vertex stage.
        int maxFragmentBufferBindCount;

        // The maximum number of buffers that you can set per command for the fragment stage.
        int maxKernelBufferBindCount;
        
        // The maximum number of buffers that you can set per command for the compute kernel.
        // Instance Properties
        bool supportRayTracing;

        // Topics
        // Declaring Command Types to Encode
        mtlpp::IndirectCommandType commandTypes;
        // The set of command types that you can encode into the indirect command buffer.
        // Declaring Command Inheritance
    };
}