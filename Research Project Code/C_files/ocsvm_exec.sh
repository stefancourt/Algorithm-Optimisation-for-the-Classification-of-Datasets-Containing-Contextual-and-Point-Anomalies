#!/bin/bash

rm -rf build   
mkdir build
cd build

cmake "/Users/stefan/Documents/GitHub/Algorithm-Optimisation-for-the-Classification-of-Datasets-Containing-Contextual-and-Point-Anomalies/Research Project Code/C_files" \
  -DCMAKE_PREFIX_PATH="/Users/stefan/Documents/GitHub/Algorithm-Optimisation-for-the-Classification-of-Datasets-Containing-Contextual-and-Point-Anomalies/Research Project Code/venv/lib/python3.11/site-packages/pybind11/share/cmake" \
  -DPython_EXECUTABLE="/Users/stefan/Documents/GitHub/Algorithm-Optimisation-for-the-Classification-of-Datasets-Containing-Contextual-and-Point-Anomalies/Research Project Code/venv/bin/python3"

make