#!/bin/bash

# Magic build script to build project

# Make build directory if does not exist
mkdir -p build

# Change into build directory so everything ends up there
# Known as out-of-source build
cd build/

# Call cmake on the directory containing CMakeLists and location of the source code
# This generates the makefile
cmake ..

# Execute the makefile generated above
make #VERBOSE=1 # Uncomment the verbose to help if not building

