//
// Created by Jamie Briggs on 01/12/2025.
//

#include <gtest/gtest.h>
#include <memory>

#include "../../cpp/day8/Circuits.h"
#include "../../cpp/day8/JunctionBox.h"

using namespace D8;

TEST(Circuits_Tests, ShouldInitialize) {
  // Given
  JunctionBox boxOne("1,2,3");
  JunctionBox boxTwo("4,5,6");
  JunctionBox boxThree("7,8,9");
  std::vector boxes = {boxOne, boxTwo, boxThree};
  // When
  Circuits circuits(boxes);
  // Then
  auto circuitsVector = circuits.getCircuits();
  ASSERT_EQ(circuitsVector[0][0], 0);
  ASSERT_EQ(circuitsVector[1][0], 1);
  ASSERT_EQ(circuitsVector[2][0], 2);
}

TEST(Circuits_Tests, ShouldMergeTwoClosestCircuits) {
  // Given
  JunctionBox boxOne("1,2,3");
  JunctionBox boxTwo("2,4,6");
  JunctionBox boxThree("100,25,10");
  std::vector boxes = {boxOne, boxTwo, boxThree};
  Circuits circuits(boxes);
  // When
  circuits.mergeNextClosestCircuits();
  // Then
  const auto circuitsVector = circuits.getCircuits();
  ASSERT_EQ(circuitsVector.size(), 2);
  ASSERT_EQ(circuitsVector[0][0], 0);
  ASSERT_EQ(circuitsVector[0][1], 1);
  ASSERT_EQ(circuitsVector[1][0], 2);
}

TEST(Circuits_Tests, ShouldMergeAllCircuits) {
  // Given
  JunctionBox boxOne("1,2,3");
  JunctionBox boxTwo("2,4,6");
  JunctionBox boxThree("100,25,10");
  std::vector boxes = {boxOne, boxTwo, boxThree};
  Circuits circuits(boxes);
  // When
  circuits.mergeNextClosestCircuits();
  circuits.mergeNextClosestCircuits();
  // Then
  const auto circuitsVector = circuits.getCircuits();
  ASSERT_EQ(circuitsVector.size(), 1);
  ASSERT_EQ(circuitsVector[0][0], 0);
  ASSERT_EQ(circuitsVector[0][1], 1);
  ASSERT_EQ(circuitsVector[0][2], 2);
}
