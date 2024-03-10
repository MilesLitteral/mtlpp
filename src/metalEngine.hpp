#include <stddef.h>
#include <string>
#include <filesystem>
#include "../mtlpp.hpp"

namespace mtlpp {
    const unsigned int arrayLength = 10; //1 << 24;
    const unsigned int bufferSize = arrayLength * sizeof(float);

    //xcrun -sdk macosx metal -c add.metal -o add.air
    //xcrun -sdk macosx metallib add.air -o add.metallib

    //xcrun -sdk macosx metal -c operations.metal -o operations.air
    //xcrun -sdk macosx metallib operations.air -o operations.metallib

    //define metal reflections here 
    void mtlAddArrays(const float* inA, const float* inB, float* result, int length);
    //end define Metal Reflections

    class MetalEngine {
        mtlpp::Device _mDevice = mtlpp::Device::CreateSystemDefaultDevice();
        mtlpp::ComputePipelineState _mFunctionPSO;
        mtlpp::CommandQueue _mCommandQueue;
        // mtlpp::Buffer _mBufferA;
        // mtlpp::Buffer _mBufferB;
        // mtlpp::Buffer _mBufferResult;
        ns::Error* error; //nullptr

        MetalEngine();
        MetalEngine(mtlpp::Device device);
        MetalEngine(ns::String libraryPath, ns::String mtlFunction, mtlpp::Device device);
        MetalEngine(ns::String mtlFunction, mtlpp::Device device);
        MetalEngine(const char src[], ns::String functionName, mtlpp::Device device);
        void generateRandomFloatData(mtlpp::Buffer buffer);
        void commitRandomFloatData(mtlpp::Buffer   buffer, char* floatData);
        void prepareData(mtlpp::Device device);
        void sendComputeCommand(mtlpp::CommandQueue commandQueue);
        //void encodeCommand(mtlpp::ComputeCommandEncoder computeEncoder);
        void encodeCommand(mtlpp::ComputeCommandEncoder computeEncoder, mtlpp::Buffer buffer);
        void encodeCommand(mtlpp::ComputeCommandEncoder computeEncoder, mtlpp::Buffer buffer, mtlpp::Buffer buffer2);
        void encodeCommand(mtlpp::ComputeCommandEncoder computeEncoder, mtlpp::Buffer buffer, mtlpp::Buffer buffer2, mtlpp::Buffer buffer3);
        void encodeCommand(mtlpp::ComputeCommandEncoder computeEncoder, mtlpp::Buffer buffers[], mtlpp::Buffer bufferR);
        void execute();
        void verifyResults();
    };

    class MetalRenderingEngine {
        mtlpp::Device _mDevice = mtlpp::Device::CreateSystemDefaultDevice();
        mtlpp::ComputePipelineState _mFunctionPSO;
        mtlpp::CommandQueue _mCommandQueue;
        // mtlpp::Buffer _mBufferA;
        // mtlpp::Buffer _mBufferB;
        // mtlpp::Buffer _mBufferResult;
        ns::Error* error; //nullptr

        MetalRenderingEngine();
        MetalRenderingEngine(mtlpp::Device device);
        MetalRenderingEngine(ns::String libraryPath, ns::String mtlFunction, mtlpp::Device device);
        MetalRenderingEngine(ns::String mtlFunction, mtlpp::Device device);
        MetalRenderingEngine(const char src[], ns::String functionName, mtlpp::Device device);

        void initializeRenderBuffer();
        void prepareData(mtlpp::Device device);
        void sendComputeCommand(mtlpp::CommandQueue commandQueue);
        void encodeCommand(mtlpp::ComputeCommandEncoder computeEncoder);
        void encodeCommand(mtlpp::ComputeCommandEncoder computeEncoder, mtlpp::Buffer buffer);
        void encodeCommand(mtlpp::ComputeCommandEncoder computeEncoder, mtlpp::Buffer buffer, mtlpp::Buffer buffer2);
        void encodeCommand(mtlpp::ComputeCommandEncoder computeEncoder, mtlpp::Buffer buffer, mtlpp::Buffer buffer2, mtlpp::Buffer buffer3);
        void encodeCommand(mtlpp::ComputeCommandEncoder computeEncoder, mtlpp::Buffer buffers[], mtlpp::Buffer bufferR);
        void verifyResults();
        void execute();
    };

    class MetalRenderingEngineCPU {
        mtlpp::IndirectCommandBuffer _indirectCommandBuffer;

        // #if TARGET_IOS
        //     supportICB = Device(); //[_view.device supportsFeatureSet:MTLFeatureSet_iOS_GPUFamily3_v4];
        // #else
        //     supportICB = Device(); //[_view.device supportsFeatureSet:MTLFeatureSet_macOS_GPUFamily2_v1];
        // #endif

        #if defined TARGET_MACOS || defined(__IPHONE_13_0)
                // Indicate that the render pipeline state object will be set in the render command encoder
                // (not by the indirect command buffer).
                // On iOS, this property only exists on iOS 13 and later.  It defaults to YES in earlier
                // versions
                if (@available(iOS 13.0, *)) {
                    icbDescriptor.inheritPipelineState = YES;
                }
        #endif

        MetalRenderingEngineCPU();
        MetalRenderingEngineCPU(mtlpp::Device device);

        void encodeDrawCommand (int vertexStart);
        void encodeBlitCommands();
        void executeICB();
    };
}