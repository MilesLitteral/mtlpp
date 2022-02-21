#!/bin/bash -ex

cd "$(dirname "${BASH_SOURCE[0]}")"

build_experiment()
{
    local ver=$1
    local output="../build/macos_$ver"
    local objcflags="-std=c++11 -x objective-c++ -mmacosx-version-min=$ver"
    local cppflags="-std=c++11 -mmacosx-version-min=$ver -fnative-half-type -fallow-half-arguments-and-returns"
    local ldflags="-framework Metal -framework MetalKit -framework Cocoa -framework CoreFoundation -fobjc-link-runtime"

    #-cc1 -fnative-half-type -fallow-half-arguments-and-returns
    rm -Rf $output
    mkdir -p $output

    clang++ $objcflags -c ../mtlpp.mm -o $output/mtlpp.o
    clang++ $cppflags $ldflags ../fut++/Mtl++/main.cpp $output/mtlpp.o -o $output/metalFut
    xcrun -sdk macosx metal -c ../fut++/Mtl++/fut.metal -o $output/fut.air
    xcrun -sdk macosx metallib $output/fut.air -o $output/fut.metallib
    
    echo "Complete Build: Futhark Metal"
}

    build_experiment 10.12
