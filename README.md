[![license](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/naleksiev/mtlpp/blob/master/LICENSE)
[![Build Status](https://travis-ci.org/naleksiev/mtlpp.svg?branch=master)](https://travis-ci.org/naleksiev/mtlpp)
## mtlpp - C++/Objective-C++ wrapper around Metal

Complete wrapper around Metal (Apple's low-level graphics API).

```c++
#include "mtlpp.hpp"

int main()
{
    mtlpp::Device device = mtlpp::Device::CreateSystemDefaultDevice();

    mtlpp::CommandQueue commandQueue = device.NewCommandQueue();
    mtlpp::CommandBuffer commandBuffer = commandQueue.CommandBuffer();

    mtlpp::TextureDescriptor textureDesc = mtlpp::TextureDescriptor::Texture2DDescriptor(
        mtlpp::PixelFormat::RGBA8Unorm, 320, 240, false);
    textureDesc.SetUsage(mtlpp::TextureUsage::RenderTarget);
    mtlpp::Texture texture = device.NewTexture(textureDesc);

    // ...

    return 0;
}
```

### Main features
 * Complete API wrapper (iOS 10, tvOS 10, and OS X 10.12).
 * Objective-C free headers - allow compiling agains the Metal API on any platform (*no linking on platforms without Metal*).
 * Configurable AVAILABILITY and DEPRECATED validation.
 * Amalgamated ```mtlpp.hpp``` and ```mtlpp.mm``` - or use the contents of ```src/``` folder.


### Interop
 **mtlpp** uses Toll-Free Bridging. The example below demonstrates how ```MTKView``` (MetalKit) can interop with **mtlpp**.
 ```objective-c
    MTKView * mtkView;

    // Objective-C to C++
    mtlpp::Device device = ns::Handle{ (__bridge void*)mtkView.device };

    // C++ to Objective-C
    mtkView.device = (__bridge id<MTLDevice>)device.GetPtr();
```

This version has additional support for later MSL version features (Dynamic Library creation, Binary Archives, etc)

## Compile metallib from .metal shaders:
```xcrun -sdk macosx metal -c MyLibrary.metal -o MyLibrary.air```
   xcrun -sdk macosx metallib MyLibrary.air   -o MyLibrary.metallib```

## Precompile Shaders on the Command Line
```xcrun -sdk macosx metal -Os MyLibrary.metal```
```xcrun -sdk macosx metal -Os MyLibrary.metal```

## Generate a Symbol File with a Single Command (For Dylib/Dynamic Linking support of a .metallib)
```xcrun -sdk macosx metal -frecord-sources=flat Shadow.metal PointLights.metal DirectionalLight.metal```

## Generate a Symbol File with Multiple Commands
You can also generate a Metal library’s symbol file with multiple commands, which may be more appropriate for your workflow than the single-command technique. 
For those scenarios, you can generate each Metal library and its companion symbol file by following these steps:

Compile each Metal source file to a Metal AIR (Apple Intermediate Representation) file.
Generate a Metal library with the source by linking its AIR files.

Separate the library’s source and save it as a companion symbol file.
First, compile each Metal source file to a Metal AIR file by passing the -c option to the compiler.

```xcrun -sdk macosx metal -c -frecord-sources Shadow.metal
xcrun -sdk macosx metal -c -frecord-sources PointLights.metal
xcrun -sdk macosx metal -c -frecord-sources DirectionalLight.metal```
The -frecord-sources option tells the Metal compiler to embed the symbols in the AIR output file for that command. However, this command doesn’t create a separate symbols file at this time, which is why the -frecord-sources option doesn’t include the =flat suffix.

Next, generate a Metal library by linking the AIR files.
```xcrun -sdk macosx metal -frecord-sources -o LightsAndShadow.metallib Shadow.air PointLights.air DirectionalLight.air```

Separate the sources from the library and create a companion symbol file by running the metal-dsymutil command.
```xcrun -sdk macosx metal-dsymutil -flat -remove-source LightsAndShadow.metallib```

Further Reading: https://developer.apple.com/documentation/metal/shader_libraries/generating_and_loading_a_metal_library_symbol_file
