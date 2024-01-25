cmake_minimum_required(VERSION 3.25.1)

# Set compilers
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define clang warnings options
set(CLANG_WARNINGS
        -Wall
        -Wextra # reasonable and standard
        -Wshadow # warn the user if a variable declaration shadows one from a parent context
        -Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor.
        # This helps catch hard to track down memory errors
        -Wold-style-cast # warn for c-style casts
        -Wcast-align # warn for potential performance problem casts
        -Wunused # warn on anything being unused
        -Woverloaded-virtual # warn if you overload (not override) a virtual function
        -Wpedantic # warn if non-standard C++ is used
        -Wconversion # warn on type conversions that may lose data
        -Wsign-conversion # warn on sign conversions
        -Wnull-dereference # warn if a null dereference is detected
        -Wdouble-promotion # warn if float is implicit promoted to double
        -Wformat=2 # warn on security issues around functions that format output (ie printf)
        -Wimplicit-fallthrough # warn on statements that fallthrough without an explicit annotation
)

set(CMAKE_CXX_CLANG_TIDY clang-tidy)

# Export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
        compass
        VERSION 0.1.0
        LANGUAGES CXX
)

# Configure version header
configure_file(
        "${PROJECT_SOURCE_DIR}/version.h.in"
        "${PROJECT_BINARY_DIR}/version.h"
)

add_subdirectory("compass")
add_subdirectory("lab")
add_subdirectory("thirdparty/gsl")

# Add GSL as an interface library
add_library(Microsoft.GSL INTERFACE)
target_include_directories(Microsoft.GSL INTERFACE "thirdparty/gsl/include")

# Add clang warnings options to both C and C++ targets
target_compile_options(compass PRIVATE ${CLANG_WARNINGS})
target_compile_options(lab PRIVATE ${CLANG_WARNINGS})
