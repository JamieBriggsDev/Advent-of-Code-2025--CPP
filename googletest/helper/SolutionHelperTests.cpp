//
// Created by Jamie Briggs on 05/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/helper/SolutionInput.h"
#include "../testHelper/InputUtils.h"

using namespace std;

TEST(SolutionInputTests, ShouldSplitInput) {
  // Given
  string rawInput =
    "row 1\n"
    "row 2\n"
    "\n"
    "row a\n"
    "row b\n"
  ;
  const auto input = InputUtils::convertToVector(rawInput);
  const auto solutionInput = new helper::SolutionInput(input);
  // When
  const auto result = solutionInput->getSplitTestInput("");
  // Then
  ASSERT_EQ(2, result.size());
  ASSERT_EQ("row 1", result[0][0]);
  ASSERT_EQ("row 2", result[0][1]);
  ASSERT_EQ("row a", result[1][0]);
  ASSERT_EQ("row b", result[1][1]);
}