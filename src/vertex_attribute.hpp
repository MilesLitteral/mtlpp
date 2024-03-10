#include "ns.hpp"
#include "mtlpp.hpp"

namespace mtlpp {
    // A MTLVertexAttribute object represents an attribute for per-vertex 
    // input in a vertex function. You use vertex attribute objects to 
    // inspect the inputs of a vertex function by examining the vertexAttributes 
    // property of the corresponding MTLFunction object.
    class VertexAttribute : ns::Object {
        // The name of the attribute.
        ns::String name;
        // The index of the attribute, as declared in Metal shader source code.
        int attributeIndex;
        // The data type for the attribute, as declared in Metal shader source code.
        mtlpp::DataType attributeType;
        // A Boolean value that indicates whether this vertex attribute is active.
        bool isActive;
        // A Boolean value that indicates whether this vertex attribute represents control point data.
        bool isPatchControlPointData;
        // A Boolean value that indicates whether this vertex attribute represents patch data.
        bool isPatchData;

        VertexAttribute();
        VertexAttribute(ns::String name, int index, mtlpp::DataType attributeT, bool active, bool patchControl, bool patchData);
    }
}