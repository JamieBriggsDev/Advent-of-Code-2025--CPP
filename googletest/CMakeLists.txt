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
        example/ExampleTests.cpp
        helper/SolutionHelperTests.cpp
        testHelper/InputUtils.h
        testHelper/InputUtils.cpp
)

# Set optimization flags for Release configuration

target_link_libraries(Google_Tests_run gtest gtest_main)