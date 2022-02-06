#!/bin/bash -ex

cd "$(dirname "${BASH_SOURCE[0]}")"

build_experiment()
{
    local ver=$1
    local output="../build/macos_$ver"
    local objcflags="-std=c++11 -x objective-c++ -mmacosx-version-min=$ver"
    local cppflags="-std=c++11 -mmacosx-version-min=$ver"
    local ldflags="-framework Metal -framework MetalKit -framework Cocoa -framework CoreFoundation -fobjc-link-runtime"

    rm -Rf $output
    mkdir -p $output

    clang++ $objcflags -c ../mtlpp.mm -o $output/mtlpp.o
    clang++ $cppflags $ldflags ../fut++/Mtl++/main.cpp $output/mtlpp.o -o $output/metalAdder
    xcrun -sdk macosx metal -c ../fut++/Mtl++/add.metal -o $output/add.air
    xcrun -sdk macosx metallib $output/add.air -o $output/add.metallib
    
    echo "Complete Build: Experiment"
}

    build_experiment 10.12
