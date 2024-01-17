cmake_minimum_required(VERSION 3.25.1)

# Set compilers
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("compass" VERSION 0.1.0)

add_subdirectory("compass")

add_subdirectory("lab")
