namespace mtlpp {

    //Topics
    //Creating a Set of Command Types
    //init(rawValue: UInt)
    struct IndirectCommandType {
        //Initializes the set of command types from a raw integer value.
        //Specifying Command Types
        IndirectCommandType draw;                      // A draw call command.
        IndirectCommandType drawIndexed;               //An indexed draw call command.
        IndirectCommandType drawPatches;               //A draw call command for tessellated patches.
        IndirectCommandType drawIndexedPatches;        //An indexed draw call command for tessellated patches.
        IndirectCommandType concurrentDispatch;        //A compute command using a grid aligned to threadgroup boundaries.
        IndirectCommandType concurrentDispatchThreads; //A compute command using an arbitrarily sized grid.
    };
}