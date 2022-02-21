/*
See LICENSE folder for this sample’s licensing information.

Abstract:
Implementation of split view controller for iOS.
*/

#include "AAPLSplitViewController.h"

class AAPLSplitViewController {
    int preferredDisplayMode;
    
    void viewDidLoad() {
        preferredDisplayMode = UISplitViewController.DisplayMode.oneBesideSecondary();
    };
};

class  AAPLSplitViewController;


