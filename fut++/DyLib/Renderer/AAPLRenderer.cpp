/*
See LICENSE folder for this sample’s licensing information.

Abstract:
Implementation of the renderer class that performs Metal setup and per-frame rendering.
*/

#include <simd/simd.h>
#include <MetalKit/MetalKit.h>

#include "AAPLRenderer.h"
#include "AAPLMathUtilities.h"

// Include header shared between C code here, which executes Metal API commands, and .metal files
#include "AAPLShaderTypes.h"
#include "../../../mtlpp.hpp"

// The max number of command buffers in flight
static const int AAPLMaxFramesInFlight = 3;

// Main class performing the rendering
class AAPLRenderer
{
    mtlpp::Device _device = mtlpp::Device::CreateSystemDefaultDevice();
    mtlpp::CommandQueue _commandQueue;
    mtlpp::CommandBuffer _commandBuffer = _commandQueue.CommandBuffer();

    //dispatch_semaphore_t _inFlightSemaphore;
    mtlpp::Buffer _frameDataBuffer = _device.NewBuffer(AAPLMaxFramesInFlight, mtlpp::ResourceOptions::StorageModeManaged);
    int _frameNumber;

    mtlpp::RenderPipelineState _renderPipeline;
    mtlpp::DepthStencilState _depthState;
    mtlpp::Texture _colorMap;
    mtlpp::Buffer _positionBuffer;
    mtlpp::Buffer _texCoordBuffer;
    mtlpp::Buffer _indexBuffer;
    mtlpp::Texture _colorTarget;

    mtlpp::RenderPassDescriptor *_renderPassDescriptor;

    mtlpp::VertexDescriptor *_vertexDescriptor;
    // Projection matrix calculated as a function of view size
    matrix_float4x4 _projectionMatrix;
    float _rotation;

    mtlpp::ComputePipelineState _computePipeline;
    mtlpp::ComputePipelineDescriptor *_baseDescriptor;
    mtlpp::Size _dispatchExecutionSize;
    mtlpp::Size _threadsPerThreadgroup;
    int _threadgroupMemoryLength;


// Initialize with the MetalKit view with the Metal device used to render.  This MetalKit view
// object will also be used to set the pixelFormat and other properties of the drawable
class initWithMetalKitView
{
    initWithMetalKitView(MTKView* mtkView)
    {
        _device = mtkView.device;
        _inFlightSemaphore = dispatch_semaphore_create(AAPLMaxFramesInFlight);
        mtkView.loadMetal();
        MTK::loadAssets;
    }
};

// Create the Metal render state objects including shaders and render state pipeline objects
void loadMetal(MTKView* mtkView)
{
    mtkView.setUpView();

    mtlpp::Library metalLibrary = this.loadMetallib();

    this.createBuffers();
    this.createRenderStateWithLibrary(metalLibrary);
    this.createComputePipelineWithLibrary(metalLibrary);

    _commandQueue = _device.newCommandQueue();
}

// Load the Metal library created in the "Build Executable Metal Library" build phase.
// This library includes the functions in AAPLShaders.metal and the UserDylib.metallib
// created in the "Build Dynamic Metal Library" build phase.
mtlpp::Library loadMetallib(mtlpp::Device _device)
{
    ns::Error *error;

    mtlpp::Library library = _device.NewLibrary("AAPLShaders.metallib", error);

    assert(library);
    if(library == NULL){
        printf("Failed to load AAPLShaders dynamic metal library: %@", error);
    }

    return library;
}

// // Set up properties of the view
// void setUpView(MTKView* mtkView)
// {
//     mtkView.colorPixelFormat = MTLPixelFormatBGRA8Unorm;
//     mtkView.sampleCount = 1;
// }

// Create buffers modified each frame to animate the cube
void createBuffers()
{
    for(int i = 0; i < AAPLMaxFramesInFlight; i++)
    {
        _frameDataBuffer[i] = _device.NewBuffer(sizeof(AAPLPerFrameData), mtlpp::ResourceOptions::StorageModeShared);
        _frameDataBuffer[i].label = "FrameDataBuffer";
    }
}

/// Create the render pass descriptor, render pipeline state object, and depth state object to render the cube.
void createRenderStateWithLibrary(mtlpp::Library metallib)
{
    ns::Error *error;

    // Set up render pass descriptor
    {
        _renderPassDescriptor = new mtlpp::RenderPassDescriptor();
        _renderPassDescriptor->GetColorAttachments()[0].SetClearColor(mtlpp::ClearColor(0, 0, 0, 1));
        _renderPassDescriptor->GetColorAttachments()[0].SetLoadAction(mtlpp::LoadAction::Clear); // LoadActionClear);
        _renderPassDescriptor->GetColorAttachments()[0].SetStoreAction(mtlpp::StoreAction::Store);

        _renderPassDescriptor->GetDepthAttachment().SetLoadAction(mtlpp::LoadAction::Clear);
        _renderPassDescriptor->GetDepthAttachment().SetStoreAction(mtlpp::StoreAction::DontCare);
    }

    // Set up render pipeline
    {
        _vertexDescriptor = new mtlpp::VertexDescriptor();
    
        _vertexDescriptor->GetAttributes()[AAPLVertexAttributePosition].SetFormat(mtlpp::VertexFormat::Float3);
        _vertexDescriptor->GetAttributes()[AAPLVertexAttributePosition].SetOffset(0);
        _vertexDescriptor->GetAttributes()[AAPLVertexAttributePosition].SetBufferIndex(AAPLBufferIndexMeshPositions);

        _vertexDescriptor->GetAttributes()[AAPLVertexAttributeTexcoord].SetFormat(mtlpp::VertexFormat::Float2);
        _vertexDescriptor->GetAttributes()[AAPLVertexAttributeTexcoord].SetOffset(0);
        _vertexDescriptor->GetAttributes()[AAPLVertexAttributeTexcoord].SetBufferIndex(AAPLBufferIndexMeshGenerics);

        _vertexDescriptor->GetLayouts()[AAPLBufferIndexMeshPositions].SetStride(16);
        _vertexDescriptor->GetLayouts()[AAPLBufferIndexMeshPositions].SetStepRate(1);
        _vertexDescriptor->GetLayouts()[AAPLBufferIndexMeshPositions].SetStepFunction(MTLVertexStepFunctionPerVertex);

        _vertexDescriptor->GetLayouts()[AAPLBufferIndexMeshGenerics].SetStride(8);
        _vertexDescriptor->GetLayouts()[AAPLBufferIndexMeshGenerics].SetStepRate(1);
        _vertexDescriptor->GetLayouts()[AAPLBufferIndexMeshGenerics].SetStepFunction(MTLVertexStepFunctionPerVertex);

        // Load the vertex function from the library
        mtlpp::Function vertexFunction = metallib.NewFunction("vertexShader");

        // Load the fragment function from the library
        mtlpp::Function fragmentFunction = metallib.NewFunction("fragmentShader");

        mtlpp::RenderPipelineDescriptor *pipelineDescriptor =   new mtlpp::RenderPipelineDescriptor();
        pipelineDescriptor->SetLabel("RenderPipeline");
        pipelineDescriptor->SetSampleCount (1);
        pipelineDescriptor->SetVertexFunction(vertexFunction);
        pipelineDescriptor->SetVertexDescriptor(*_vertexDescriptor);
        pipelineDescriptor->SetFragmentFunction(fragmentFunction);
        pipelineDescriptor->GetColorAttachments()[0].SetPixelFormat(MTLPixelFormatRGBA8Unorm);
        pipelineDescriptor->SetDepthAttachmentPixelFormat(MTLPixelFormatDepth32Float);

        _renderPipeline = _device.NewRenderPipelineState(pipelineDescriptor, error);

        assert(_renderPipeline);
        if(_renderPipeline == NULL){
            printf("Failed to create render pipeline state: %@", error);
        }
    }

    // Set up depth stencil state
    {
        mtlpp::DepthStencilDescriptor *depthStateDesc = new mtlpp::DepthStencilDescriptor();
        depthStateDesc->SetDepthCompareFunction(mtlpp::CompareFunction(mtlpp::CompareFunction::Less));
        depthStateDesc->SetDepthWriteEnabled(true);
        _depthState = _device.NewDepthStencilState(*depthStateDesc);
    }
}

void createComputePipelineWithLibrary(mtlpp::Library metallib)
{
    ns::Error *error;

    mtlpp::Function kernelFunction = metallib.NewFunction("dylibKernel");
    _baseDescriptor = new mtlpp::ComputePipelineDescriptor();
    _baseDescriptor->SetComputeFunction(kernelFunction);
    mtlpp::ComputePipelineDescriptor *descriptor = new mtlpp::ComputePipelineDescriptor();
    descriptor->SetComputeFunction(_baseDescriptor->GetComputeFunction());
    
    _computePipeline = _device.NewComputePipelineState(descriptor, NULL, error);
    assert(_computePipeline)
    if(_computePipeline == NULL){
        printf("Error creating pipeline which links library from source: %@", error);
    }
}

/// Load assets into metal objects
void loadAssets()
{
    // Create a buffer with positions to draw the cube.
        static const vector_float3 cubePositions[] =
        {
            // Front
            { -1, -1,  1 },
            { -1,  1,  1 },
            {  1,  1,  1 },
            {  1, -1,  1 },

            // Top
            { -1,  1,  1 },
            { -1,  1, -1 },
            {  1,  1, -1 },
            {  1,  1,  1 },

            // Right
            {  1, -1,  1 },
            {  1,  1,  1 },
            {  1,  1, -1 },
            {  1, -1, -1 },

            // Back
            { -1,  1, -1 },
            { -1, -1, -1 },
            {  1, -1, -1 },
            {  1,  1, -1 },

            // Bottom
            { -1, -1, -1 },
            { -1, -1,  1 },
            {  1, -1,  1 },
            {  1, -1, -1 },

            // Left
            { -1, -1, -1 },
            { -1,  1, -1 },
            { -1,  1,  1 },
            { -1, -1,  1 }
        };

        _positionBuffer = _device.NewBuffer(cubePositions, sizeof(cubePositions), 0);

    // Create a buffer with texture coordinates to draw the cube.
        static const vector_float2 cubeTexCoords[] =
        {
            // Front
            { 0, 0 },
            { 0, 1 },
            { 1, 1 },
            { 1, 0 },

            // Top
            { 0, 0 },
            { 0, 1 },
            { 1, 1 },
            { 1, 0 },

            // Right
            { 0, 0 },
            { 0, 1 },
            { 1, 1 },
            { 1, 0 },

            // Back
            { 1, 0 },
            { 1, 1 },
            { 0, 1 },
            { 0, 0 },

            // Bottom
            { 0, 0 },
            { 0, 1 },
            { 1, 1 },
            { 1, 0 },

            // Right
            { 0, 0 },
            { 0, 1 },
            { 1, 1 },
            { 1, 0 },
        };

        _texCoordBuffer = _device.NewBuffer(cubeTexCoords, sizeof(cubeTexCoords), mtlpp::ResourceOptions::StorageModeManaged);

    // Create the index buffer to draw the cube.
        static uint16_t indices[] =
        {
            // Front
             0,  2,  1,  0,  3,  2,

            // Top
             4,  6,  5,  4,  7,  6,

            // Right
             8, 10,  9,  8, 11, 10,

            // Back
            12, 14, 13, 12, 15, 14,

            // Bottom
            16, 18, 17, 16, 19, 18,

            // Left
            20, 22, 21, 20, 23, 22,
        };

        _indexBuffer = _device.NewBuffer(indices, sizeof(indices), mtlpp::ResourceOptions::StorageModeManaged);

    // Load color texture from asset catalog
    {
        MTKTextureLoader* textureLoader = MTKTextureLoader(_device);
        
        enum textureLoaderOptions 
        {
            MTKTextureLoaderOptionTextureUsage,       //: @(MTLTextureUsageShaderRead),
            MTKTextureLoaderOptionTextureStorageMode //: @(MTLStorageModePrivate)
        };

        ns::Error *error;

        _colorMap = textureLoader("ColorMap", 1.0, NULL, textureLoaderOptions::MTKTextureLoaderOptionTextureUsage, &error);

        assert(_colorMap);
        if(_colorMap == NULL){
            printf("Error creating the Metal texture, error: %@.", error);
        }
    }
}

//Update any scene state before encoding rendering commands to our drawable
void updateSceneState()
{
    unsigned int frameDataBufferIndex = _frameNumber % AAPLMaxFramesInFlight;

    AAPLPerFrameData *frameData = (AAPLPerFrameData*)_frameDataBuffer[frameDataBufferIndex].contents;

    frameData->projectionMatrix = _projectionMatrix;

    vector_float3 rotationAxis = { 1, 1, 0 };
    matrix_float4x4 modelMatrix = matrix4x4_rotation(_rotation, rotationAxis);
    matrix_float4x4 viewMatrix = matrix4x4_translation(0.0, 0.0, -6.0);

    frameData->modelViewMatrix = matrix_multiply(viewMatrix, modelMatrix);

    _rotation += .01;
}

/// Update the 3D projection matrix with the given size
void updateProjectionMatrixWithSize(mtlpp::Size  size)
{
    /// Respond to drawable size or orientation changes here
    float aspect = size.Width / (float)size.Height;
    _projectionMatrix = matrix_perspective_right_hand(65.0f * (M_PI / 180.0f), aspect, 0.1f, 100.0f);
}

// Create render targets for compute kernel inputs
void createRenderTargetsWithSize(mtlpp::Size  size)
{
    MTLTextureDescriptor *renderTargetDesc = new MTLTextureDescriptor();

    // Set up properties common to both color and depth textures.
    renderTargetDesc.width = size.width;
    renderTargetDesc.height = size.height;
    renderTargetDesc.storageMode = MTLStorageModePrivate;

    // Set up a color render texture target.
    renderTargetDesc.pixelFormat = MTLPixelFormatRGBA8Unorm;
    renderTargetDesc.usage = MTLTextureUsageRenderTarget | MTLTextureUsageShaderRead;
    _colorTarget =  _device.NewTexture(renderTargetDesc);

    // Set up a depth texture target.
    renderTargetDesc.pixelFormat = MTLPixelFormatDepth32Float;
    renderTargetDesc.usage = MTLTextureUsageRenderTarget;
    mtlpp::Texture depthTarget = _device.NewTexture(renderTargetDesc);

    // Set up the render pass descriptor with newly created textures.
    _renderPassDescriptor.colorAttachments[0].texture = _colorTarget;
    _renderPassDescriptor.depthAttachment.texture = depthTarget;
}

/// Called whenever view changes orientation or layout is changed
void mtkView(MTKView * view, mtlpp::Size size)
{
    // Update the aspect ratio and projection matrix since the view orientation or size has changed.
    this.updateProjectionMatrixWithSize(size);
    this.createRenderTargetsWithSize(size);
}

//Called whenever the view needs to render
void drawInMTKView(MTKView* view)
{
    unsigned int frameDataBufferIndex = _frameNumber % AAPLMaxFramesInFlight;

    dispatch_semaphore_wait(_inFlightSemaphore, DISPATCH_TIME_FOREVER);

    // this.updateSceneState();

    // Render cube to offscreen texture
    {
        mtlpp::CommandBuffer commandBuffer = _commandQueue.CommandBuffer();
        commandBuffer.SetLabel(ns::String("Render CommandBuffer"));

        mtlpp::RenderCommandEncoder renderEncoder = commandBuffer.RenderCommandEncoder(_renderPassDescriptor);
        // Render cube
        renderEncoder.SetLabel("Render Encoder");
        renderEncoder.PushDebugGroup("Render Cube");

        renderEncoder.SetFrontFacingWinding(mtlpp::Winding::CounterClockwise);
        renderEncoder.SetCullMode(mtlpp::CullMode::Back);
        renderEncoder.SetRenderPipelineState(_renderPipeline);
        renderEncoder.SetDepthStencilState(_depthState);
        renderEncoder.SetVertexBuffer(_positionBuffer, 0, AAPLBufferIndexMeshPositions);
        renderEncoder.SetVertexBuffer(_texCoordBuffer, 0, AAPLBufferIndexMeshGenerics);
        renderEncoder.SetVertexBuffer(_frameDataBuffer[frameDataBufferIndex], 0, AAPLBufferIndexFrameData);
        renderEncoder.SetFragmentBuffer(_frameDataBuffer[frameDataBufferIndex], 0, AAPLBufferIndexFrameData);
        renderEncoder.SetFragmentTexture(_colorMap, AAPLTextureIndexColorMap);
        renderEncoder.DrawIndexed(mtlpp::PrimitiveType::Triangle, 36, mtlpp::IndexType::UInt16, _indexBuffer, 0);
        renderEncoder.PopDebugGroup();
        renderEncoder.EndEncoding();

        commandBuffer.Commit();
    }

    // Use compute pipeline from function in dylib to process offscreen texture
    if(_computePipeline && view.currentDrawable)
    {
        mtlpp::CommandBuffer commandBuffer = _commandQueue.CommandBuffer();
        commandBuffer.SetLabel(ns::String("Compute CommandBuffer"));

        __block dispatch_semaphore_t block_sema = _inFlightSemaphore;
        [commandBuffer addCompletedHandler:^(id<MTLCommandBuffer> buffer)
         {
            dispatch_semaphore_signal(block_sema);
        }];

        mtlpp::ComputeCommandEncoder computeEncoder = commandBuffer.ComputeCommandEncoder();
        computeEncoder.label = "Compute Encoder";
        computeEncoder.SetComputePipelineState(_computePipeline);
        computeEncoder.SetTexture(_colorTarget, AAPLTextureIndexComputeIn);
        computeEncoder.SetTexture(view.currentDrawable.texture, AAPLTextureIndexComputeOut);
        computeEncoder.DispatchThreads(MTLSizeMake(view.drawableSize.width, view.drawableSize.height, 1)
                  threadsPerThreadgroup:MTLSizeMake(16, 16, 1);

        computeEncoder.EndEncoding();

        commandBuffer.Present(view.currentDrawable);
        commandBuffer.Commit();
    }


    _frameNumber++;
}

/// Compile a dylib with the given program string then create a compute pipeline with the dylib
void compileDylibWithString(ns::String* programString)
{
    ns::Error *error;
    
    mtlpp::CompileOptions* options = new mtlpp::CompileOptions();
    options.libraryType = MTLLibraryTypeDynamic;
    options.installName = ns::String("@executable_path/userCreatedDylib.metallib";

    mtlpp::Library lib = _device.NewLibraryWithSource(programString, options, &error);
    if(!lib && error)
    {
        printf("Error compiling library from source: %@", error);
        return;
    }
    
    id<MTLDynamicLibrary> dynamicLib = [_device newDynamicLibrary:lib
                                                            error:&error];
    if(!dynamicLib && error)
    {
        printf("Error creating dynamic library from source library: %@", error);
        return;
    }
    
    mtlpp::ComputePipelineDescriptor *descriptor = new mtlpp::ComputePipelineDescriptor();
    descriptor.SetComputeFunction(_baseDescriptor.computeFunction);
    descriptor.SetInsertLibraries(dynamicLib);
    
    mtlpp::ComputePipelineState previousComputePipeline = _computePipeline;
    _computePipeline = _device.NewComputePipelineState(descriptor, MTLPipelineOptionNone, NULL, error);
        if(!_computePipeline && error)
        {
            printf("Error creating pipeline library from source library, using previous pipeline: %@", error);
            _computePipeline = previousComputePipeline;
            return;
        }
    }
}

