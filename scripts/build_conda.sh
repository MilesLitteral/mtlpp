#!/bin/bash -ex


build_conda(){
    local ver=$1
    local output="../build/macos_$ver"
    chmod +x ~/Downloads/Miniforge3-MacOSX-arm64.sh
    sh ~/Downloads/Miniforge3-MacOSX-arm64.sh
    source ~/miniforge3/bin/activate
}

build_conda