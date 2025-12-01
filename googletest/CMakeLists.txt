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
        ../cpp/helper/SolutionInput.h
        ../cpp/helper/SolutionInput.cpp
        ../cpp/helper/FileReader.cpp
        ../cpp/helper/FileReader.h
        ../cpp/helper/StringUtils.cpp
        ../cpp/helper/StringUtils.h
        ../cpp/core/Pair.h
        core/PairTests.cpp
)

# Set optimization flags for Release configuration

target_link_libraries(Google_Tests_run gtest gtest_main)