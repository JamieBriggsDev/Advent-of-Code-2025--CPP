//
// Created by Jamie Briggs on 01/12/2025.
//

#include <gtest/gtest.h>

#include "../../cpp/day8/JunctionBox.h"

using namespace D8;

TEST(JunctionBox_Tests, ShouldInitialize) {
  // Given
  std::string row = "1,2,3";
  // When
  JunctionBox box(row);
  // Then
  ASSERT_EQ(box.getX(), 1);
  ASSERT_EQ(box.getY(), 2);
  ASSERT_EQ(box.getZ(), 3);
}

TEST(JunctionBox_Tests, ShouldInitializeLargerNumbers) {
  // Given
  std::string row = "123456,23456789,34567";
  // When
  JunctionBox box(row);
  // Then
  ASSERT_EQ(box.getX(), 123456);
  ASSERT_EQ(box.getY(), 23456789);
  ASSERT_EQ(box.getZ(), 34567);
}

TEST(JunctionBox_Tests, ShouldFindSimpleEuclideanDistance) {
  // Given
  JunctionBox boxOne("1,2,3");
  JunctionBox boxTwo("4,6,8");
  // When
  float result = boxOne.getEuclideanDistance(boxTwo);
  // Then
  ASSERT_NEAR(result, 7.07, 0.01);
}
