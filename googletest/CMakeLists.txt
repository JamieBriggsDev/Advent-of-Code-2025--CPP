cmake_minimum_required(VERSION 3.30.5)
# 'Google_test' is the subproject name
project(Google_tests)

set(CMAKE_CXX_STANDARD 23)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(Google_Tests_run
        ../cpp/helper/AOCInitializer.h
        ../cpp/helper/AOCInitializer.cpp
        ../cpp/helper/SolutionInput.h
        ../cpp/helper/SolutionInput.cpp
        ../cpp/helper/FileReader.cpp
        ../cpp/helper/FileReader.h
        ../cpp/core/Pair.h
        core/PairTests.cpp
        ../cpp/day1/Dial.cpp
        ../cpp/day1/Dial.h
        ../cpp/day1/Day01.h
        ../cpp/day1/Day01.cpp
        day1/DialTest.cpp
        day1/Day1Test.cpp
        example/Example_Tests.cpp
        helper/SolutionInputTests.cpp
        testHelper/InputUtils.h
        testHelper/InputUtils.cpp
        ../cpp/day2/Day02.h
        ../cpp/day2/Day02.cpp
        ../cpp/core/Range.cpp
        ../cpp/core/Range.h
        core/RangeTest.cpp
        ../cpp/day2/InvalidIdFinder.cpp
        ../cpp/day2/InvalidIdFinder.h
        day2/InvalidIdFinderTest.cpp
        ../cpp/day3/Day03.cpp
        ../cpp/day3/Day03.h
        ../cpp/day3/BatteryBank.cpp
        ../cpp/day3/BatteryBank.h
        day3/BatteryBankTest.cpp
        ../cpp/day4/Day04.h
        ../cpp/day4/Day04.cpp
        ../cpp/day4/PaperGrid.cpp
        ../cpp/day4/PaperGrid.h
        day4/PaperGridTest.cpp
        ../cpp/day5/Day05.cpp
        ../cpp/day5/Day05.h
        ../cpp/day7/Beam.cpp
        ../cpp/day7/Beam.h
        day7/BeamTests.cpp
        ../cpp/day7/Day07.cpp
        ../cpp/day7/Day07.h
        ../cpp/day7/BeamPath.h
        ../cpp/day8/Day08.h
        ../cpp/day8/Day08.cpp
        ../cpp/day8/JunctionBox.h
        ../cpp/day8/JunctionBox.cpp
        day8/JunctionBoxTests.cpp
        ../cpp/day8/Circuits.cpp
        ../cpp/day8/Circuits.h
        day8/CircuitsTests.cpp
        ../cpp/day9/Day09.cpp
        ../cpp/day9/Day09.h
        ../cpp/day9/GreenTileFinder.cpp
        ../cpp/day9/GreenTileFinder.h
        day9/GreenTileFinderTests.cpp
)

# Set optimization flags for Release configuration
target_link_libraries(Google_Tests_run gtest gtest_main)