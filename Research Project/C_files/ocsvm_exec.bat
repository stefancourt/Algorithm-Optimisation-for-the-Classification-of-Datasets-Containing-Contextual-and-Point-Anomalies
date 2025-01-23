@echo off

rem Remove the "build" directory if it exists
if exist build (
    rmdir /s /q build
)

rem Create the "build" directory
mkdir build
cd build

rem Run CMake with the appropriate paths and options
cmake "C:/Users/Stefan/Documents/GitHub/Algorithm-Optimisation-for-the-Classification-of-Datasets-Containing-Contextual-and-Point-Anomalies/Research Project/C_files" ^
  -DCMAKE_PREFIX_PATH="C:\Users\Stefan\Documents\GitHub\Algorithm-Optimisation-for-the-Classification-of-Datasets-Containing-Contextual-and-Point-Anomalies\Research Project\venv\Lib\site-packages\pybind11" ^
  -DPython_EXECUTABLE="C:\Users\Stefan\Documents\GitHub\Algorithm-Optimisation-for-the-Classification-of-Datasets-Containing-Contextual-and-Point-Anomalies\Research Project\venv\Scripts\python.exe"

rem Build the project
cmake --build .

cd ..