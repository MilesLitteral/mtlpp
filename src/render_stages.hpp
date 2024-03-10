namespace mtlpp {
  // Render stages provide finer control for specifying when synchronization must occur, 
  // allowing for vertex and fragment processing to overlap in execution.
  struct RenderStages {

    //Specifying a Render Stage
    static RenderStages vertex;
    //The vertex rendering stage.
    static RenderStages fragment;
    //The fragment rendering stage.
    static RenderStages tile;
    //The tile rendering stage.
    //Initializing a Render Stage
    // init(rawValue: UInt)
    //Initializes a render stage from a raw value.
    //Type Properties
    static RenderStages mesh;
    static RenderStages object;
  }
}