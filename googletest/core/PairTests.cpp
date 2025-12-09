//
// Created by Jamie Briggs on 01/12/2024.
//

#include "../../cpp/core/Pair.h"

#include <gtest/gtest.h>

using namespace core;

TEST(Pair_Tests, ShouldReturnDistanceOfZero)
{
  // Given
  Pair myPair(0,0);
  // When
  int result = myPair.distance();
  // Then
  EXPECT_EQ(0, result);
}

TEST(Pair_Tests, ShouldReturnDistanceOfFiveWhenFirstValueSmaller)
{
  // Given
  Pair myPair(0,5);
  // When
  int result = myPair.distance();
  // Then
  EXPECT_EQ(5, result);
}


TEST(Pair_Tests, ShouldReturnDistanceOfFiveWhenSecondValueSmaller)
{
  // Given
  Pair myPair(5,0);
  // When
  int result = myPair.distance();
  // Then
  EXPECT_EQ(5, result);
}


TEST(Pair_Tests, ShouldReturnAreaBetweenTwoPairs) {
  // Given
  Pair pairOne(1,1);
  Pair pairTwo(3,3);
  // When
  long result = pairOne.areaBetween(pairTwo);
  // Then
  ASSERT_EQ(result, 9);
}

TEST(Pair_Tests, ShouldReturnAreaBetweenTwoPairsLarger) {
  // Given
  Pair pairOne(2,5);
  Pair pairTwo(9,7);
  // When
  long result = pairOne.areaBetween(pairTwo);
  // Then
  ASSERT_EQ(result, 24);
}

TEST(Pair_Tests, ShouldReturnAreaBetweenTwoPairsLargerExample) {
  // Given
  Pair pairOne(2,5);
  Pair pairTwo(11,1);
  // When
  long result = pairOne.areaBetween(pairTwo);
  // Then
  ASSERT_EQ(result, 50);
}