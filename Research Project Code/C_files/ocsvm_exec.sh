#!/bin/bash

rm -rf build   
mkdir build
cd build

cmake "Enter Your Absolute Path Here" \
  -DCMAKE_PREFIX_PATH="Enter Your Absolute Path Here" \
  -DPython_EXECUTABLE="Enter Your Absolute Path Here"

make