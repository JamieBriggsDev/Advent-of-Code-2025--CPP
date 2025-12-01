//
// Created by Jamie Briggs on 01/12/2025.
//

#include <gtest/gtest.h>

#include "../../cpp/day1/Day01.h"
#include "../../cpp/day1/Dial.h"


TEST(Day1Tests, ShouldMoveDialRight) {
  // Given
  auto dial = std::make_unique<solutions::Day01>();
  auto listOfInput = std::vector<std::string>{"R50"};
  auto solutionInput = std::make_unique<SolutionInput>(listOfInput);
  // When
  auto result = dial->solvePartOne(solutionInput.get());
  // Then
  EXPECT_EQ(result, "1");
}

TEST(Day1Tests, ShouldMoveDialLeft) {
  // Given
  auto dial = std::make_unique<solutions::Day01>();
  auto listOfInput = std::vector<std::string>{"L50"};
  auto solutionInput = std::make_unique<SolutionInput>(listOfInput);
  // When
  auto result = dial->solvePartOne(solutionInput.get());
  // Then
  EXPECT_EQ(result, "1");
}


TEST(Day1Tests, ShouldHitZeroMultiple) {
  // Given
  auto dial = std::make_unique<solutions::Day01>();
  auto listOfInput = std::vector<std::string>{"L50", "R200", "L200"};
  auto solutionInput = std::make_unique<SolutionInput>(listOfInput);
  // When
  auto result = dial->solvePartOne(solutionInput.get());
  // Then
  EXPECT_EQ(result, "3");
}

TEST(Day1Tests, PartTwoTests) {
  // Given
  auto dial = std::make_unique<solutions::Day01>();
  auto listOfInput = std::vector<std::string>{"L50", "R200", "L200"};
  auto solutionInput = std::make_unique<SolutionInput>(listOfInput);
  // When
  auto result = dial->solvePartTwo(solutionInput.get());
  // Then
  EXPECT_EQ(result, "5");
}

TEST(Day1Tests, PartTwoTestsLargeExample) {
  // Given
  auto dial = std::make_unique<solutions::Day01>();
  auto listOfInput = std::vector<std::string>{"L1000"};
  auto solutionInput = std::make_unique<SolutionInput>(listOfInput);
  // When
  auto result = dial->solvePartTwo(solutionInput.get());
  // Then
  EXPECT_EQ(result, "10");
}

TEST(Day1Tests, PartTwoMultipleMovements) {
  // Given
  auto dial = std::make_unique<solutions::Day01>();
  auto listOfInput = std::vector<std::string>{"L50", "R100", "L200"};
  auto solutionInput = std::make_unique<SolutionInput>(listOfInput);
  // When
  auto result = dial->solvePartTwo(solutionInput.get());
  // Then
  EXPECT_EQ(result, "4");
}
