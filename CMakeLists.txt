cmake_minimum_required(VERSION 3.30.5)
project(aoc2025)

set(CMAKE_CXX_STANDARD 23)

add_executable(aoc2025 main.cpp
        cpp/day1/Day01.cpp
        cpp/day1/Day01.h
        cpp/helper/FileReader.cpp
        cpp/helper/FileReader.h
        cpp/helper/SolutionInput.cpp
        cpp/helper/SolutionInput.h
        cpp/Day.h
        cpp/helper/AOCInitializer.cpp
        cpp/helper/AOCInitializer.h
        cpp/helper/StringUtils.cpp
        cpp/helper/StringUtils.h
        cpp/core/Pair.h
        cpp/core/WordSearchRow.cpp
        cpp/core/WordSearchRow.h
        cpp/core/WordSearchGrid.h
        cpp/core/WordSearchGrid.cpp
        cpp/core/AocException.cpp
        cpp/core/AocException.h
        cpp/core/HashConfig.h
)

add_subdirectory(googletest)
