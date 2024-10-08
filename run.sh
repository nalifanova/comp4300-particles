#!/bin/bash

export PATH=$PATH:`dirname $(which cmake)`
# create directories and move it there
mkdir -p Particles/build && cd Particles/build

# Run cmake and wait for the result
if cmake ../..; then
    if make; then # Happy case with build
        ./bin/Particles
    else
        echo "Something went wrong with the build process."
    fi
else
    echo "Error: CMake failed."
fi
