cmake_minimum_required(VERSION 3.30.5)
project(aoc2025)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCE_FILES
        "cpp/*.cpp"
        "cpp/*.h"
)

add_executable(aoc2025 main.cpp ${SOURCE_FILES}
        cpp/core/MemoryHelper.h)

add_subdirectory(googletest)
