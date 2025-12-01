//
// Created by Jamie Briggs on 01/12/2025.
//

#include <filesystem>


#include "../../cpp/day1/Day01.h"
#include "../../cpp/helper/AOCInitializer.h"
#include "../../cpp/helper/SolutionInput.h"
#include "gtest/gtest.h"

using namespace solutions;

class ExampleTests : public ::testing::Test {
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

TEST_F(ExampleTests, Day1_Part1) {
  // Given
  const auto input = getTestInput("testData/day1.txt");
  constexpr auto day = std::unique_ptr<Day01>();
  // When
  const auto result = day->solvePartOne(input);
  // Then
  EXPECT_EQ(result, "3");
}

TEST_F(ExampleTests, Day1_Part2) {
  // Given
  const auto input = getTestInput("testData/day1.txt");
  constexpr auto day = std::unique_ptr<Day01>();
  // When
  const auto result = day->solvePartTwo(input);
  // Then
  EXPECT_EQ(result, "6");
}
