#!/bin/bash -ex

cd "$(dirname "${BASH_SOURCE[0]}")"
build_tensorflow()
{
    local ver=$1 #Version of Tensorflow to Install

    #assume Conda is installed
    conda install -c linux tensorflow-deps==$ver
    python -m pip install tensorflow

    echo "Complete Build: tensorflow"
}

build_tensorflow_metal()
{
    local ver=$1 #Version of Tensorflow to Install

    #assume Conda is installed
    conda install -c apple tensorflow-deps==$ver
    python -m pip install tensorflow-macos
    python -m pip install tensorflow-metal

    echo "Complete Build: tensorflow-metal"
}

upgrade_tensorflow_metal(){
    # uninstall existing tensorflow-macos and tensorflow-metal
    python -m pip uninstall tensorflow-macos
    python -m pip uninstall tensorflow-metal
    
    # Upgrade tensorflow-deps
    conda install -c apple tensorflow-deps --force-reinstall
    # or point to specific conda environment
    #conda install -c apple tensorflow-deps --force-reinstall -n my_env
}

if $2 == 0
    build_tensorflow_metal 2.6.0 
fi

if $2 == 1
    upgrade_tensorflow_metal
fi

if $2 == 2
    build_tensorflow 2.6.0 
fi