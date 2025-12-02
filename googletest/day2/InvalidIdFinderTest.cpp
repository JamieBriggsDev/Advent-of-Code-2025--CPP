//
// Created by Jamie Briggs on 01/12/2025.
//

#include "../../cpp/day2/Range.h"
#include <gtest/gtest.h>

#include "../../cpp/day2/InvalidIdFinder.h"

using namespace D2;

TEST(InvalidIdFinder_Tests, isIdInvalid_ShouldReturnFalseForSingleDigit)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalid(1);
  // Then
  EXPECT_FALSE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalid_ShouldReturnFalseWhenTwoDigitNonRepeating)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalid(12);
  // Then
  EXPECT_FALSE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalid_ShouldReturnFalseWhenThreeDigitNonRepeating)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalid(123);
  // Then
  EXPECT_FALSE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalid_ShouldReturnTrueWhenTwoDigitAndRepeatingDigits)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalid(22);
  // Then
  EXPECT_TRUE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalid_ShouldReturnFalseWhenThreeDigit)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalid(212);
  // Then
  EXPECT_FALSE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalid_ShouldReturnFalseWhenThreeDigitsSameCauseNotRepeatingPattern)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalid(222);
  // Then
  EXPECT_FALSE(result);
}


TEST(InvalidIdFinder_Tests, isIdInvalid_ShouldReturnTrueWhenFourDigitsSame)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalid(2222);
  // Then
  EXPECT_TRUE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalid_ShouldReturnTrueWhenTwoDigitPatternExists)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalid(1212);
  // Then
  EXPECT_TRUE(result);
}


TEST(InvalidIdFinder_Tests, isIdInvalid_ShouldReturnFalseWhenFourDigits_NoPatternIncluded)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalid(2142);
  // Then
  EXPECT_FALSE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalid_ShouldReturnFalseWhenFiveDigits)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalid(12412);
  // Then
  EXPECT_FALSE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalid_ShouldReturnTrueWhenSixDigits_ThreeDigitPatterns)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalid(123123);
  // Then
  EXPECT_TRUE(result);
}




TEST(InvalidIdFinder_Tests, isIdInvalidComplex_ShouldReturnFalseForSingleDigit)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalidComplex(1);
  // Then
  EXPECT_FALSE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalidComplex_ShouldReturnFalseWhenTwoDigitNonRepeating)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalidComplex(12);
  // Then
  EXPECT_FALSE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalidComplex_ShouldReturnFalseWhenThreeDigitNonRepeating)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalidComplex(123);
  // Then
  EXPECT_FALSE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalidComplex_ShouldReturnTrueWhenTwoDigitAndRepeatingDigits)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalidComplex(22);
  // Then
  EXPECT_TRUE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalidComplex_ShouldReturnFalseWhenThreeDigit)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalidComplex(212);
  // Then
  EXPECT_FALSE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalidComplex_ShouldReturnTrueWhenThreeDigitsSame)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalidComplex(222);
  // Then
  EXPECT_TRUE(result);
}


TEST(InvalidIdFinder_Tests, isIdInvalidComplex_ShouldReturnTrueWhenFourDigitsSame)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalidComplex(2222);
  // Then
  EXPECT_TRUE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalidComplex_ShouldReturnTrueWhenTwoDigitPatternExists)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalidComplex(1212);
  // Then
  EXPECT_TRUE(result);
}


TEST(InvalidIdFinder_Tests, isIdInvalidComplex_ShouldReturnFalseWhenFourDigits_NoPatternIncluded)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalidComplex(2142);
  // Then
  EXPECT_FALSE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalidComplex_ShouldReturnFalseWhenFiveDigits)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalidComplex(12412);
  // Then
  EXPECT_FALSE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalidComplex_ShouldReturnTrueWhenSixDigits_ThreeDigitPatterns)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalidComplex(123123);
  // Then
  EXPECT_TRUE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalidComplex_ShouldReturnTrueWhenSixDigits_ThreePatterns)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalidComplex(121212);
  // Then
  EXPECT_TRUE(result);
}

TEST(InvalidIdFinder_Tests, isIdInvalidComplex_ShouldReturnTrueWhenEightDigits_FourPatterns)
{
  // Given / When
  const auto result = InvalidIdFinder::isIdInvalidComplex(12121212);
  // Then
  EXPECT_TRUE(result);
}

