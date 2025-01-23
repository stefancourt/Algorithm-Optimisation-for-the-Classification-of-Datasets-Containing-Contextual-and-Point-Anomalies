cmake_minimum_required(VERSION 3.10)
project(OCSVM)

# Find pybind11
find_package(pybind11 REQUIRED)
find_package(Python REQUIRED COMPONENTS Interpreter Development)

# Add the target library
add_library(ocsvm MODULE OCSVM.cpp)

# Use pybind11 to link the target
target_link_libraries(ocsvm PRIVATE pybind11::module)
target_include_directories(ocsvm PRIVATE ${PYTHON_INCLUDE_DIRS})

# Set the library name for Python
set_target_properties(ocsvm PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}" SUFFIX "${PYTHON_MODULE_EXTENSION}")
