/*
See LICENSE folder for this sample’s licensing information.

Abstract:
Header for the renderer class that performs Metal setup and per-frame rendering.
*/

#ifndef AAPLRenderer_h
#define AAPLRenderer_h

#include <MetalKit/MetalKit.h>
#include "../mtlpp.hpp

// Platform independent renderer class
class AAPLRenderer : ns::Object<mtlpp::ViewDelegate>
{
    void initWithMetalKitView(mtlpp::View *mtkView);
    void compileDylibWithString(ns::String programString);
}

#endif /* AAPLRenderer_h */
