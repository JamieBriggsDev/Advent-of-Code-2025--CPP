//
// Created by Jamie Briggs on 01/12/2025.
//

#include "../../cpp/day1/Dial.h"
#include <gtest/gtest.h>

using namespace Day1;

TEST(DialTests, ShouldInitializeDial)
{
  // Given
  auto dial = std::make_unique<Dial>(0);
  // When
  auto result = dial->getValue();
  // Then
  EXPECT_TRUE(result == 0);
}


TEST(DialTests, ShouldMoveRightWithoutLoop)
{
  // Given
  auto dial = std::make_unique<Dial>(0);
  // When
  dial->moveDial(15);
  // Then
  auto result = dial->getValue();
  EXPECT_EQ(result, 15);
}


TEST(DialTests, ShouldMoveLeftWithoutLoop)
{
  // Given
  auto dial = std::make_unique<Dial>(50);
  // When
  dial->moveDial(-15);
  // Then
  auto result = dial->getValue();
  EXPECT_EQ(result, 35);
}

TEST(DialTests, ShouldMoveBackTo99)
{
  // Given
  auto dial = std::make_unique<Dial>(0);
  // When
  dial->moveDial(-1);
  // Then
  auto result = dial->getValue();
  EXPECT_EQ(result, 99);
}

TEST(DialTests, ShouldMoveBackTo99Twice)
{
  // Given
  auto dial = std::make_unique<Dial>(0);
  // When
  dial->moveDial(-101);
  // Then
  auto result = dial->getValue();
  EXPECT_EQ(result, 99);
}

TEST(DialTests, ShouldMoveForwardTo0)
{
  // Given
  auto dial = std::make_unique<Dial>(99);
  // When
  dial->moveDial(1);
  // Then
  auto result = dial->getValue();
  EXPECT_EQ(result, 0);
}

TEST(DialTests, ShouldMoveForwardTo0Twice)
{
  // Given
  auto dial = std::make_unique<Dial>(99);
  // When
  dial->moveDial(101);
  // Then
  auto result = dial->getValue();
  EXPECT_EQ(result, 0);
}

TEST(DialTests, ShouldCountNumberOfTimesEndsOnZero)
{
  // Given
  auto dial = std::make_unique<Dial>(50);
  // When
  dial->moveDial(-50);
  // Then
  auto result = dial->getTotalTimesDialEndsOnZero();
  EXPECT_EQ(result, 1);
}

TEST(DialTests, ShouldEndOnZero3Times)
{
  // Given
  auto dial = std::make_unique<Dial>(50);
  // When
  dial->moveDial(-50);
  dial->moveDial(-100);
  dial->moveDial(-100);
  // Then
  auto result = dial->getTotalTimesDialEndsOnZero();
  EXPECT_EQ(result, 3);
}

TEST(DialTests, ShouldHitZeroMultipleTimesMovingRight)
{
  // Given
  auto dial = std::make_unique<Dial>(50);
  // When
  dial->moveDial(250);
  // Then
  auto result = dial->getTotalTimesDialTouchesZero();
  EXPECT_EQ(result, 3);
}


TEST(DialTests, ShouldHitZeroMultipleTimesMovingLeft)
{
  // Given
  auto dial = std::make_unique<Dial>(50);
  // When
  dial->moveDial(-250);
  // Then
  auto result = dial->getTotalTimesDialTouchesZero();
  EXPECT_EQ(result, 3);
}
