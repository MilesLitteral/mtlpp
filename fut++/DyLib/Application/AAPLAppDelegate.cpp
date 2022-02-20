/*
See LICENSE folder for this sample’s licensing information.

Abstract:
Implementation of the cross-platform app delegate.
*/

#include "AAPLAppDelegate.h"

class AAPLAppDelegate
{
    bool application;
    UIApplication * application; 

    bool didFinishLaunchingWithOptions(ns::Dictionary *launchOptions)
    {
        return true;
    }

    bool applicationShouldTerminateAfterLastWindowClosed(ns::Application* sender)
    {
        return true;
    }
};

