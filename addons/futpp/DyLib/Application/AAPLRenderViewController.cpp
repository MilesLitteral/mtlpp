/*
See LICENSE folder for this sample’s licensing information.

Abstract:
Implementation of the cross-platform Metal rendering view controller.
*/

#include "AAPLRenderViewController.h"
#include "../Renderer/AAPLRenderer.h"
#include "../../../mtlpp.hpp"
#include "AAPLEditViewController.h"

#if defined(TARGET_IOS)
#include "AAPLSplitViewController.h"
#endif

class AAPLRenderViewController
{
    MTKView *_view;
    AAPLRenderer *_renderer;


    void viewDidLoad()
    {
        //[super viewDidLoad];
        
        _view = mtlpp::View* self.view;

    #if defined(TARGET_IOS)
        _view.device = mtlpp::CreateSystemDefaultDevice();
        
        assert(_view.device, @"Metal is not supported on this device");
        
        if (@available(iOS 14.0, *))
        {
            assert(_view.device.supportsDynamicLibraries, "Dynamic libraries are not supported on this device. Must use a device with an A13 or newer");
        }
        else
        {
            NSLog(@"Dynamic libraries are only supported on iOS 14 and higher");
            return;
        }
    #else
        _view.device = selectMetalDevice();
        assert(_view.device);
    #endif
        _view.framebufferOnly = false;
        _renderer = new AAPLRenderer(); //alloc] initWithMetalKitView:_view];
        assert(_renderer);
        _renderer.initWithMetalKitView(_view);

    #if defined(TARGET_IOS)
        double  contentScaleFactor = _view.contentScaleFactor;
        _renderer.mtkView(_view drawableSizeWillChange)
        CGSizeMake(_view.bounds.size.width * contentScaleFactor,
                    _view.bounds.size.height * contentScaleFactor);
    #else
        double backingScaleFactor = NSScreen(mainScreen, backingScaleFactor);
        _renderer.mtkView(_view, drawableSizeWillChange);
        CGSizeMake(_view.bounds.size.width * backingScaleFactor, _view.bounds.size.height * backingScaleFactor)];
    #endif
        _view.delegate = _renderer;
    }

    #if defined(TARGET_IOS)
    void viewWillAppear(bool animated)
    {
        //[super viewWillAppear:animated];
        
        // Find the split view controller
        UIViewController *parentViewController = this;
        while(parentViewController != nil && !typeof(parentViewController) == AAPLSplitViewController class)
        {
            parentViewController = parentViewController;
        }
        printf("Could not establish expected parent view controller");
        AAPLSplitViewController *splitViewController = (AAPLSplitViewController *)parentViewController;
        
        // Find the edit view controller
        ns::Array<UIViewController *> *viewControllers = splitViewController.viewControllers;
        AAPLEditViewController *editViewController;
        for(int x < 0; x < viewControllers; x++)
        {
            if(typeof(viewController) == AAPLEditViewController)
            {
                editViewController = (AAPLEditViewController *)viewController;
                break;
            }
        }
        if(editViewController != NULL)
        {
            editViewController.renderer = _renderer;
        }
    }
    #else
    void viewWillAppear()
    {
        AAPLEditViewController *editViewController = (AAPLEditViewController*)(NSSplitViewController*)parentViewController(splitViewItems, firstObject, viewController);
        if(editViewController != NULL)
        {
            editViewController->renderer = _renderer;
        }
    }

    mtlpp::Device selectMetalDevice()
    {
        mtlpp::Device devices[] = mtlpp::Device::CopyAllDevices();
        
        //Search for high-powered devices that support dynamic libraries
        for(int x = 0; x < devices.length; x++)
        {
            //mtlpp::Device device in devices
            if(!devices[x].isLowPower && devices[x].supportsDynamicLibraries)
            {
                return devices[x];
            }
        }
        //Search for any device that supports dynamic libraries
        for(int x = 0; x < devices.length; x++)
        {
            if(devices[x].supportsDynamicLibraries)
            {
                return devices[x];
            }
        }   
        return NULL;
    }
    #endif
};