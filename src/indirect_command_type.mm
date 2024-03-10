#include <indirect_command_type.hpp>
#include <Metal/MTLIndirectCommandType>

namespace mtlpp {
    struct IndirectCommandType {
        // Topics
        // Creating a Set of Command Types
        //init(rawValue: UInt)

        // Initializes the set of command types from a raw integer value.
        // Specifying Command Types
        static mtlpp::IndirectCommandType draw;                      //A draw call command.
        static mtlpp::IndirectCommandType drawIndexed;               // An indexed draw call command.
        static mtlpp::IndirectCommandType drawPatches;               //A draw call command for tessellated patches.
        static mtlpp::IndirectCommandType drawIndexedPatches;        //An indexed draw call command for tessellated patches.
        static mtlpp::IndirectCommandType concurrentDispatch;        //A compute command using a grid aligned to threadgroup boundaries.
        static mtlpp::IndirectCommandType concurrentDispatchThreads; //A compute command using an arbitrarily sized grid.
    }
}