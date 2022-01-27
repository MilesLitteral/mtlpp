#include <stddef.h>
#include "mtlpp.hpp"

const unsigned int arrayLength = 1 << 24;
const unsigned int bufferSize = arrayLength * sizeof(float);

//using namespace mtlpp::ResourceOptions;
//remember to add a .metal file
void mtlAddArrays(const float* inA,
                const float* inB,
                float* result,
                int length)
{
    for (int index = 0; index < length ; index++)
    {
        result[index] = inA[index] + inB[index];
    }
}

class MetalAdder
{
    public:
        mtlpp::Device _mDevice;

        // The compute pipeline generated from the compute kernel in the .metal shader file.
        mtlpp::ComputePipelineState _mAddFunctionPSO;

        // The command queue used to pass commands to the device.
        mtlpp::CommandQueue _mCommandQueue;

        // Buffers to hold data.
        mtlpp::Buffer _mBufferA;
        mtlpp::Buffer _mBufferB;
        mtlpp::Buffer _mBufferResult;

    MetalAdder(mtlpp::Device device)
    {
        _mDevice = device;
        std::runtime_error* error = NULL;

        // Load the shader files with a .metal file extension in the project

        mtlpp::Library defaultLibrary = device.NewDefaultLibrary();
        mtlpp::Function addFunction = defaultLibrary.NewFunction("mtlAddArrays");

        // Create a compute pipeline state object.
        //_mAddFunctionPSO = device.NewComputePipelineState(addFunction, error);
    
        _mCommandQueue = device.NewCommandQueue();
    }


    void generateRandomFloatData(mtlpp::Buffer buffer)
    {
        float* dataPtr = (float*)buffer.GetContents();

        for (unsigned long index = 0; index < arrayLength; index++)
        {
            dataPtr[index] = (float)rand()/(float)(RAND_MAX);
        }
    }

    void prepareData(mtlpp::Device device)
    {
        // Allocate three buffers to hold our initial data and the result.
        _mBufferA = device.NewBuffer(bufferSize, mtlpp::ResourceOptions::StorageModeShared);
        _mBufferB = device.NewBuffer(bufferSize, mtlpp::ResourceOptions::StorageModeShared);
        _mBufferResult = device.NewBuffer(bufferSize, mtlpp::ResourceOptions::StorageModeShared);

        generateRandomFloatData(_mBufferA);
        generateRandomFloatData(_mBufferB);
    }


    void sendComputeCommand(mtlpp::CommandQueue commandQueue)
    {
        // Create a command buffer to hold commands.
        
        mtlpp::CommandBuffer commandBuffer = commandQueue.CommandBuffer();
        //assert(commandBuffer != NULL);

        // Start a compute pass.
        mtlpp::ComputeCommandEncoder computeEncoder = mtlpp::ComputeCommandEncoder(computeEncoder);// computeCommandEncoder];
        //assert(computeEncoder != NULL);

        encodeAddCommand(computeEncoder);
        // End the compute pass.
        computeEncoder.EndEncoding();

        // Execute the command.
        commandBuffer.Commit();

        // Normally, you want to do other work in your app while the GPU is running,
        // but in this example, the code simply blocks until the calculation is complete.
        commandBuffer.WaitUntilCompleted();

        verifyResults(_mBufferA, _mBufferB, _mBufferResult);
    }


    void encodeAddCommand(mtlpp::ComputeCommandEncoder computeEncoder) {

        // Encode the pipeline state object and its parameters.
        computeEncoder.SetComputePipelineState(_mAddFunctionPSO);
        computeEncoder.SetBuffer(_mBufferA, 0, 0);
        computeEncoder.SetBuffer(_mBufferB, 0, 1);
        computeEncoder.SetBuffer(_mBufferResult, 0, 2);
        //_mBufferResult offset:x atIndex:y

        mtlpp::Size gridSize = mtlpp::Size(arrayLength, 1, 1);

        // Calculate a threadgroup size.
        uint32_t threadGroupSize = _mAddFunctionPSO.GetMaxTotalThreadsPerThreadgroup();
        if (threadGroupSize > arrayLength)
        {
            threadGroupSize = arrayLength;
        }
        mtlpp::Size threadgroupSize = mtlpp::Size(threadGroupSize, 1, 1);

        // Encode the compute command.
        computeEncoder.DispatchThreadgroups(gridSize, threadgroupSize);
    }


    void verifyResults(mtlpp::Buffer _mBufferA, mtlpp::Buffer _mBufferB, mtlpp::Buffer _mBufferResult)
    {
        float* a = (float*)_mBufferA.GetContents();
        float* b = (float*)_mBufferB.GetContents();
        float* result = (float*)_mBufferResult.GetContents();

        for (unsigned long index = 0; index < arrayLength; index++)
        {
            if (result[index] != (a[index] + b[index]))
            {
                printf("Compute ERROR: index=%lu result=%g vs %g=a+b\n",
                    index, result[index], a[index] + b[index]);
                assert(result[index] == (a[index] + b[index]));
            }
        }
        printf("Compute results as expected\n");
    }
};


int main(int argc, char * argv[]){
        mtlpp::Device device = mtlpp::Device::CreateSystemDefaultDevice();

        // Create the custom object used to encapsulate the Metal code.
        // Initializes objects to communicate with the GPU.
        MetalAdder adder = MetalAdder(device);
        
        // Create buffers to hold data
        adder.prepareData(device);
        
        // Send a command to the GPU to perform the calculation.
        adder.sendComputeCommand(adder._mCommandQueue);

        printf("Execution finished");
}
