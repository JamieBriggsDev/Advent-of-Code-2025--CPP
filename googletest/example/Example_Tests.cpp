//
// Created by Jamie Briggs on 01/12/2015.
//

#include <filesystem>


#include "../../cpp/day1/Day01.h"
#include "../../cpp/day2/Day02.h"
#include "../../cpp/day3/Day03.h"
#include "../../cpp/day4/Day04.h"
#include "../../cpp/day5/Day05.h"
#include "../../cpp/day7/Day07.h"
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


TEST_F(Example_Tests, Day3_Part1) {
  // Given
  const auto input = getTestInput("testData/day3.txt");
  Day03 day;
  // When
  const auto result = day.solvePartOne(input);
  // Then
  EXPECT_EQ(result, "357");
}

TEST_F(Example_Tests, Day3_Part2) {
  // Given
  const auto input = getTestInput("testData/day3.txt");
  Day03 day;
  // When
  const auto result = day.solvePartTwo(input);
  // Then
  EXPECT_EQ(result, "3121910778619");
}

TEST_F(Example_Tests, Day4_Part1) {
  // Given
  const auto input = getTestInput("testData/day4.txt");
  Day04 day;
  // When
  const auto result = day.solvePartOne(input);
  // Then
  EXPECT_EQ(result, "13");
}

TEST_F(Example_Tests, Day4_Part2) {
  // Given
  const auto input = getTestInput("testData/day4.txt");
  Day04 day;
  // When
  const auto result = day.solvePartTwo(input);
  // Then
  EXPECT_EQ(result, "43");
}

TEST_F(Example_Tests, Day5_Part1) {
  // Given
  const auto input = getTestInput("testData/day5.txt");
  Day05 day;
  // When
  const auto result = day.solvePartOne(input);
  // Then
  EXPECT_EQ(result, "3");
}

TEST_F(Example_Tests, Day5_Part2_check) {
  // Given
  const auto input = getTestInput("testData/day5.txt");
  Day05 day;
  // When
  const auto result = day.solvePartTwo(input);
  // Then
  EXPECT_EQ(result, "14");
}

TEST_F(Example_Tests, Day7_Part1) {
  // Given
  const auto input = getTestInput("testData/day7.txt");
  Day07 day;
  // When
  const auto result = day.solvePartOne(input);
  // Then
  EXPECT_EQ(result, "21");
}

/**TEST_F(Example_Tests, Day7_Part2) {
  // Given
  const auto input = getTestInput("testData/day7.txt");
  Day07 day;
  // When
  const auto result = day.solvePartTwo(input);
  // Then
  EXPECT_EQ(result, "40");
}
*/