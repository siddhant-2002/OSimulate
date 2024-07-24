cmake_minimum_required(VERSION 3.30.1)

# Set the project name
project(OSimulate)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directories
include_directories(include)

# Add the source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add the executable
add_executable(OSimulate ${SOURCES})
