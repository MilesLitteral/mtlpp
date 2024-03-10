namespace mtlpp {
    class IntersectionFunctionTable : mtlpp::Resource {
        //Overview
        //Don’t implement this protocol yourself. Instead create a MTLIntersectionFunctionTableDescriptor object and configure its properties. Then call the appropriate method on the pipeline state object that you want to use this table with:

        //Compute pipeline
        void makeIntersectionFunctionTable(mtlpp::IntersectionFunctionTableDescriptor descriptor);

        //Render pipeline
        void makeIntersectionFunctionTable(mtlpp::IntersectionFunctionTableDescriptor descriptor, mtlpp::RenderStages stage);

        //If you use the same ray-tracing functions with more than one pipeline, make a separate table for each.

        //Use the methods on this object to set the table entries to point at the intersection functions, and to provide buffers as arguments for those functions. For more information about intersection functions, see Metal Shading Language Specification.

        //Topics
        //Setting a Table Entry
        void setFunction(mtlpp::FunctionHandle    handle,  int index);
        //Sets an entry in the table.
        //Required.

        void setFunctions(mtlpp::FunctionHandle[] handle,  Range<Int> range);
        //Sets a range of entries in the table.
        //Specifying Arguments for Intersection Functions
        void setBuffer(mtlpp::Buffer buffer, int offset,   int index);
        //Sets a buffer for the intersection functions.
        //Required.

        void setBuffers(mtlpp::Buffer[] buffers, int[] offsets,    Range<Int> range);
        //Sets a range of buffers for the intersection functions.

        void setVisibleFunctionTable(mtlpp::VisibleFunctionTable table, int bufferIndex);
        //Sets a visible function table for the intersection functions.
        //Required.

        void setVisibleFunctionTables(mtlpp::VisibleFunctionTable[] functions, Range<Int> bufferRange);
        //Sets a range of visible function tables for the intersection functions.
        //Specifying Opaque Triangle Intersection Testing

        void setOpaqueTriangleIntersectionFunction(mtlpp::IntersectionFunctionSignature signature, int index);
        //Sets an entry in the intersection table to point to a system-defined opaque triangle intersection function.
        //Required.

        void setOpaqueTriangleIntersectionFunction(mtlpp::IntersectionFunctionSignature signature, ns::Range range);
        //Sets a range of entries in the intersection table to point to a system-defined opaque triangle intersection function.
        //Required.

        //Instance Properties
        mtlpp::ResourceID gpuResourceID;
        //Required.
    }
}