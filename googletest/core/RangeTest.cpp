//
// Created by Jamie Briggs on 01/12/2025.
//

#include <gtest/gtest.h>
#include "../../cpp/core/Range.h"

using namespace core;

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

TEST(Range_Tests, ShouldNotFitWithinRange) {
  // Given
  Range range(10, 15);
  // When
  // Then
  EXPECT_FALSE(range.isInRange(9));
  EXPECT_FALSE(range.isInRange(8));
  EXPECT_FALSE(range.isInRange(16));
  EXPECT_FALSE(range.isInRange(17));
}

TEST(Range_Tests, ShouldFitWithinRange) {
  // Given
  Range range(10, 15);
  // When
  // Then
  EXPECT_TRUE(range.isInRange(10));
  EXPECT_TRUE(range.isInRange(11));
  EXPECT_TRUE(range.isInRange(12));
  EXPECT_TRUE(range.isInRange(13));
  EXPECT_TRUE(range.isInRange(14));
  EXPECT_TRUE(range.isInRange(15));
}

TEST(Range_Tests, shouldNotCompress) {
  // Given
  Range rangeOne(1, 5);
  Range rangeTwo(6, 10);
  // When
  rangeOne.compressUsingRange(rangeTwo);
  // Then
  EXPECT_EQ(rangeOne.getStartId(), 1);
  EXPECT_EQ(rangeOne.getEndId(), 5);
}

TEST(Range_Tests, shouldCompressStartDate) {
  // Given
  Range rangeOne(3, 8);
  Range rangeTwo(1, 4);
  // When
  rangeOne.compressUsingRange(rangeTwo);
  // Then
  EXPECT_EQ(rangeOne.getStartId(), 5);
  EXPECT_EQ(rangeOne.getEndId(), 8);
  EXPECT_FALSE(rangeOne.getInvalid());
}

TEST(Range_Tests, shouldCompressEndDate) {
  // Given
  Range rangeOne(1, 5);
  Range rangeTwo(5, 10);
  // When
  rangeOne.compressUsingRange(rangeTwo);
  // Then
  EXPECT_EQ(rangeOne.getStartId(), 1);
  EXPECT_EQ(rangeOne.getEndId(), 4);
  EXPECT_FALSE(rangeOne.getInvalid());
}

TEST(Range_Tests, shouldMarkAsInvalid) {
  // Given
  Range rangeOne(3, 5);
  Range rangeTwo(2, 10);
  // When
  rangeOne.compressUsingRange(rangeTwo);
  // Then
  EXPECT_EQ(rangeOne.getStartId(), 3);
  EXPECT_EQ(rangeOne.getEndId(), 5);
  EXPECT_TRUE(rangeOne.getInvalid());
}