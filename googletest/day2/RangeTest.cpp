//
// Created by Jamie Briggs on 01/12/2025.
//

#include "../../cpp/day2/Range.h"
#include <gtest/gtest.h>

using namespace D2;

TEST(Range_Tests, ShouldInitializeRange)
{
  // Given
  Range range(123, 456);
  // When
  auto start = range.getStartId();
  auto end = range.getEndId();
  // Then
  EXPECT_EQ(start, 123);
  EXPECT_EQ(end, 456);
}

TEST(Range_Tests, ShouldReturnArrayOfAllRanges) {
  // Given
  Range range(10, 15);
  // When
  auto fullRange = range.getFullRange();
  // Then
  EXPECT_EQ(fullRange.size(), 6);
  EXPECT_EQ(fullRange[0], 10);
  EXPECT_EQ(fullRange[1], 11);
  EXPECT_EQ(fullRange[2], 12);
  EXPECT_EQ(fullRange[3], 13);
  EXPECT_EQ(fullRange[4], 14);
  EXPECT_EQ(fullRange[5], 15);
}
