#!/bin/bash

# Create build directory if it doesn't exist
mkdir -p build

# Navigate to build directory
cd build

# Run CMake and make
cmake -DCMAKE_POLICY_VERSION_MINIMUM=3.5 ..
make

# Run the game
./TicTacToe/TicTacToe 