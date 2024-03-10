namespace mtlpp {
    void IntersectionFunctionTable::makeIntersectionFunctionTable(mtlpp::IntersectionFunctionTableDescriptor descriptor){

    };

    //Render pipeline
    void IntersectionFunctionTable::makeIntersectionFunctionTable(mtlpp::IntersectionFunctionTableDescriptor descriptor, mtlpp::RenderStages stage:){
        
    };

    //If you use the same ray-tracing functions with more than one pipeline, make a separate table for each.

    //Use the methods on this object to set the table entries to point at the intersection functions, and to provide buffers as arguments for those functions. For more information about intersection functions, see Metal Shading Language Specification.

    // Topics
    // Setting a Table Entry
    void IntersectionFunctionTable::setFunction(mtlpp::FunctionHandle handle, int index) {
        Validate();
        [(__bridge id<MTLFunction>)m_ptr setFunction:(__bridge MTLFunctionHandle*)handle.GetPtr() index:index];
    }
    // Sets an entry in the table.
    // Required.

    void IntersectionFunctionTable::setFunctions([(MTLFunctionHandle)?], range: Range<Int>){

    }
    // Sets a range of entries in the table.
    // Specifying Arguments for Intersection Functions

    void IntersectionFunctionTable::setBuffer(mtlpp::Buffer buffer, int offset, int index){

    };
    // Sets a buffer for the intersection functions.
    // Required.

    void IntersectionFunctionTable::setBuffers(mtlpp::Buffer[] buffers, offsets: [Int], range: Range<Int>){

    };

    //Sets a range of buffers for the intersection functions.
    void IntersectionFunctionTable::setVisibleFunctionTable(mtlpp::VisibleFunctionTable table, bufferIndex: Int){

    };

    // Sets a visible function table for the intersection functions.
    // Required.

    void IntersectionFunctionTable::setVisibleFunctionTables(mtlpp::VisibleFunctionTable[], bufferRange: Range<Int>){

    };

    // Sets a range of visible function tables for the intersection functions.
    // Specifying Opaque Triangle Intersection Testing

    void IntersectionFunctionTable::setOpaqueTriangleIntersectionFunction(mtlpp::IntersectionFunctionSignature signature, int index){

    };
    //Sets an entry in the intersection table to point to a system-defined opaque triangle intersection function.
    //Required.

    void IntersectionFunctionTable::setOpaqueTriangleIntersectionFunction(signature: MTLIntersectionFunctionSignature, ns::Range range){

    };

    // Sets a range of entries in the intersection table to point to a system-defined opaque triangle intersection function.
    // Required.
    // Instance Properties
    // var gpuResourceID: MTLResourceID
    // Required.
    // Relationships
    // Inherits From
    // MTLResource
}
