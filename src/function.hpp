#include "defines.hpp"
#include "ns.hpp"

namespace mtlpp {
    enum FunctionType { //: UInt, @unchecked Sendable 
        //Topics
        vertex,
        fragment,
        kernel,
        intersection,
        visible,
        mesh,
        object
    };

    class PatchType {
        // Types of tessellation patches that can be inputs of a post-tessellation vertex function.
        // Retrieving Function Attributes
        mtlpp::VertexAttribute vertexAttributes;//: []?
        // An array that describes the vertex input attributes to a vertex function.
        // Required.
        mtlpp::Attribute stageInputAttributes;//: [MTLAttribute]?
        // An array that describes the input attributes to the function.
        // Required.
        //Retrieving Function Constants
        mtlpp::FunctionConstant functionConstantsDictionary;//: [String : MTLFunctionConstant]
        // A dictionary of function constants for a specialized function.
        // Required.
        //Creating Argument Encoders
        mtlpp::ArgumentEncoder makeArgumentEncoder(int bufferIndex);
        // Creates an argument encoder for an argument buffer that’s one of this function's arguments.
        // Required.
    };

    struct FunctionOptions{
        // Options that define how Metal creates the function object.
        // Identifying the Tessellation Patch
        mtlpp::PatchType patchType; 
        // mtlpp::FunctionOptions options;
        // The tessellation patch type of a post-tessellation vertex function.
        // Required.
        int patchControlPointCount;
        // The number of patch control points in the post-tessellation vertex function.
        // Required.
    };

    class Function {
        //Overview
        //Use MTLFunction objects to specify which shaders a Metal pipeline calls when the GPU executes commands that specify that pipeline. For more information on creating pipeline state objects, see MTLRenderPipelineDescriptor and MTLComputePipelineDescriptor.
        //A MTLFunction object is a specialized function if the shader contains function constants, otherwise it is a nonspecialized function.
        //Don’t use standard allocation and initialization techniques to create a MTLFunction object. Instead, use the function creation methods provided by the MTLLibrary protocol. To create a nonspecialized function, call the makeFunction(name:) method.
        //To create a specialized function, call one of these MTLLibrary methods:

        Function makeFunction(const ns::String name, ns::Handle completionHandler);
        Function makeFunction(const ns::String name);
        //MTLFunction objects can use a significant amount of memory; release any strong references to them after you finish creating pipeline objects.

        //Topics
        //The function’s name.
        ns::String name;
        //Required.

        //Identifying Shader Functions
        mtlpp::Device device;
        //The device object that created the shader function.
        //Required.

        //A string that identifies the shader function.
        ns::String label;
        //Required.
        
        //The shader function’s type.
        mtlpp::FunctionType functionType;
        //Required.
    };
}