#!/bin/zsh
set -e  # Exit on error

# Define build directory
BUILD_DIR="build"

# Create build directory if it doesn't exist
[[ ! -d $BUILD_DIR ]] && mkdir $BUILD_DIR

# Enter build directory
cd $BUILD_DIR

# Run CMake configuration (only if needed)
if [[ ! -f CMakeCache.txt ]]; then
    echo "Running CMake configuration..."
    cmake ..
fi

# Build the project
echo "Building the project..."
cmake --build .

# Run the program if build succeeds
EXECUTABLE="./wxApp"
if [[ -f $EXECUTABLE ]]; then
    echo "Running $EXECUTABLE..."
    $EXECUTABLE
else
    echo "Error: Executable not found!"
fi

