#include "defines.hpp"
#include "ns.hpp"

namespace mtlpp {
    enum FunctionType {
        //The type of a top-level Metal Shading Language (MSL) function.
        mtlpp::FunctionOptions options;
        //The options that Metal used to compile this function.
        //Required.
    }

    enum PatchType {
        //Types of tessellation patches that can be inputs of a post-tessellation vertex function.
        //Retrieving Function Attributes
        VertexAttribute[] vertexAttributes
        //An array that describes the vertex input attributes to a vertex function.
        //Required.
        Attribute[] stageInputAttributes,
        //An array that describes the input attributes to the function.
        //Required.
        //Retrieving Function Constants
        var functionConstantsDictionary: [String : MTLFunctionConstant];
        //A dictionary of function constants for a specialized function.
        //Required.
        //Creating Argument Encoders
        mtlpp::ArgumentEncoder makeArgumentEncoder(bufferIndex: Int);
        //Creates an argument encoder for an argument buffer that’s one of this function's arguments.
        //Required.
    }

    struct FunctionOptions{
        //Options that define how Metal creates the function object.
        //Identifying the Tessellation Patch
        PatchType patchType;
        //The tessellation patch type of a post-tessellation vertex function.
        //Required.
        int patchControlPointCount;
        //The number of patch control points in the post-tessellation vertex function.
        //Required.
    }
    
    class Function : ns::Object {
        //MTLFunction objects can use a significant amount of memory; release any strong references to them after you finish creating pipeline objects.
        //Topics
        //Identifying Shader Functions
        mtlpp::Device device;
        //The device object that created the shader function.
        //Required.
        ns::String label;
        //A string that identifies the shader function.
        //Required.
        mtlpp::FunctionType functionType;
        //The shader function’s type.
        //Required.
        ns::String name;
        //The function’s name.
        //Required.

        makeFunction(name:constantValues:);
        makeFunction(name:constantValues:completionHandler:);
    }
}