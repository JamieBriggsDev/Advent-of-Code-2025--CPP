//
// Created by Jamie Briggs on 01/12/2015.
//

#include <filesystem>


#include "../../cpp/day1/Day01.h"
#include "../../cpp/day2/Day02.h"
#include "../../cpp/helper/AOCInitializer.h"
#include "../../cpp/helper/SolutionInput.h"
#include "gtest/gtest.h"

using namespace solutions;

class Example_Tests : public ::testing::Test {
public:
  static std::filesystem::path testDir() {
    using std::filesystem::path;
    return path(__FILE__).parent_path(); // directory of ExampleTests.cpp
  }
  static SolutionInput* getTestInput(const std::string &fileName) {
    auto path = testDir() / ".." / fileName; // relative to source, not cwd
    return AOCInitializer::getInput(path);
  }

  // Setup
  void SetUp() override {}
};

TEST_F(Example_Tests, Day1_Part1) {
  // Given
  const auto input = getTestInput("testData/day1.txt");
  Day01 day;
  // When
  const auto result = day.solvePartOne(input);
  // Then
  EXPECT_EQ(result, "3");
}

TEST_F(Example_Tests, Day1_Part2) {
  // Given
  const auto input = getTestInput("testData/day1.txt");
  Day01 day;
  // When
  const auto result = day.solvePartTwo(input);
  // Then
  EXPECT_EQ(result, "6");
}


TEST_F(Example_Tests, Day2_Part1) {
  // Given
  const auto input = getTestInput("testData/day2.txt");
  Day02 day;
  // When
  const auto result = day.solvePartOne(input);
  // Then
  EXPECT_EQ(result, "1227775554");
}

TEST_F(Example_Tests, Day2_Part2) {
  // Given
  const auto input = getTestInput("testData/day2.txt");
  Day02 day;
  // When
  const auto result = day.solvePartTwo(input);
  // Then
  EXPECT_EQ(result, "4174379265");
}
