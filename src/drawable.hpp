/*
 * Copyright 2016-2017 Nikolay Aleksiev. All rights reserved.
 * License: https://github.com/naleksiev/mtlpp/blob/master/LICENSE
 */

#pragma once

#include "defines.hpp"
#include "ns.hpp"

namespace mtlpp
{
    class MetalLayer : public mtlpp::quartz::Layer {
        mtlpp::Device device;

        //The Metal device responsible for the layer’s drawable resources.
        mtlpp::Device preferredDevice;

        //The device object that the system recommends using for this layer.
        //Configuring the Layer's Drawable Objects
        mtlpp::PixelFormat pixelFormat;
        //The pixel format of the layer’s textures.
        var colorspace: CGColorSpace?
        //The color space of the rendered content.
        bool framebufferOnly;
        //A Boolean value that determines whether the layer’s textures are used only for rendering.
        var drawableSize: CGSize
        //The size, in pixels, of textures for rendering layer content.
        //Configuring Presentation Behavior
        bool presentsWithTransaction;
        //A Boolean value that determines whether the layer presents its content using a Core Animation transaction.
        bool displaySyncEnabled;
        //A Boolean value that determines whether the layer synchronizes its updates to the display’s refresh rate.
        //Configuring Extended Dynamic Range Behavior
        
        bool wantsExtendedDynamicRangeContent;
        //Enables extended dynamic range values onscreen.

        var edrMetadata: CAEDRMetadata?
        //Metadata describing the tone mapping to apply to the extended dynamic range (EDR) values in the layer.
        //Obtaining a Metal Drawable

        func nextDrawable() -> (any CAMetalDrawable)?
        //Waits until a Metal drawable is available, and then returns it.
        int maximumDrawableCount;
        //The number of Metal drawables in the resource pool managed by Core Animation.
        bool allowsNextDrawableTimeout;
        //A Boolean value that determines whether requests for a new buffer expire if the system can’t satisfy them.
        //Configuring the Metal Performance HUD
        var developerHUDProperties: [AnyHashable : Any]?
        //The properties of the Metal performance heads-up display.
    }

    class Drawable : public ns::Object
    {
    private:
        Texture texture;
        MetalLayer layer;
        
    public:
        Drawable() { }
        Drawable(const ns::Handle& handle) : ns::Object(handle) { }

        double   GetPresentedTime() const MTLPP_AVAILABLE_IOS(10_3);
        uint64_t GetDrawableID() const MTLPP_AVAILABLE_IOS(10_3);

        void Present();
        void PresentAtTime(double presentationTime);
        void PresentAfterMinimumDuration(double duration) MTLPP_AVAILABLE_IOS(10_3);
        void AddPresentedHandler(std::function<void(const Drawable&)> handler) MTLPP_AVAILABLE_IOS(10_3);
    }
    MTLPP_AVAILABLE(10_11, 8_0);
}

