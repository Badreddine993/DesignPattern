cmake_minimum_required(VERSION 3.16)
project(DesignPatternsCpp VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Include directories
include_directories(patterns)
include_directories(concepts)
include_directories(examples)

# Find required packages
find_package(Threads REQUIRED)

# Enable testing
enable_testing()

# Add subdirectories
add_subdirectory(patterns)
add_subdirectory(concepts)
add_subdirectory(examples)
add_subdirectory(tests)

# Custom target to run all examples
add_custom_target(run_examples
    COMMAND ${CMAKE_CTEST_COMMAND} --verbose
    DEPENDS all
    COMMENT "Running all examples"
)
