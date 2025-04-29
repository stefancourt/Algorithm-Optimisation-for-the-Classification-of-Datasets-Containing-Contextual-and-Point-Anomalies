@echo off

rem Remove the "build" directory if it exists
if exist build (
    rmdir /s /q build
)

rem Create the "build" directory
mkdir build
cd build

rem Run CMake with the appropriate paths and options
cmake "Enter Your Absolute Path Here" ^
  -DCMAKE_PREFIX_PATH="Enter Your Absolute Path Here" ^
  -DPython_EXECUTABLE="Enter Your Absolute Path Here"

rem Build the project
cmake --build .

cd ..