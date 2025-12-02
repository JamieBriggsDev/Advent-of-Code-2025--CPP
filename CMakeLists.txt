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
        cpp/core/Pair.h
        cpp/core/AocException.cpp
        cpp/core/AocException.h
        cpp/core/HashConfig.h
        cpp/day1/Dial.cpp
        cpp/day1/Dial.h
        cpp/day2/Day02.h
        cpp/day2/Day02.cpp
        cpp/day2/Range.cpp
        cpp/day2/Range.h
        cpp/day2/InvalidIdFinder.cpp
        cpp/day2/InvalidIdFinder.h
)

add_subdirectory(googletest)
