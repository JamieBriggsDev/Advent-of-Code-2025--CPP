//
// Created by Jamie Briggs on 01/12/2025.
//

#include <gtest/gtest.h>

#include "../../cpp/day7/Beam.h"

using namespace D7;

TEST(Beam_Tests, ShouldInitialize) {
  // Given
  std::string row = "...S...";
  // When
  Beam beam(row);
  // Then
  auto result = beam.getCurrentBeamPositions();
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], 3);
  EXPECT_EQ(beam.getTotalSplits(), 0);
}

TEST(Beam_Tests, ShouldNotSplitAndAddRow) {
  // Given
  std::string row = "...S...";
  Beam beam(row);
  // When
  beam.moveDownward(".......");
  // Then
  auto result = beam.getCurrentBeamPositions();
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], 3);
  EXPECT_EQ(beam.getTotalSplits(), 0);
}

TEST(Beam_Tests, ShouldNotSplitAndAddTwoRows) {
  // Given
  std::string row = "...S...";
  Beam beam(row);
  // When
  beam.moveDownward(".......");
  beam.moveDownward(".......");
  // Then
  auto result = beam.getCurrentBeamPositions();
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], 3);
  EXPECT_EQ(beam.getTotalSplits(), 0);
}

TEST(Beam_Tests, ShouldSplitBeam) {
  // Given
  std::string row = "...S...";
  Beam beam(row);
  // When
  beam.moveDownward("...^...");
  // Then
  auto result = beam.getCurrentBeamPositions();
  EXPECT_EQ(result.size(), 2);
  EXPECT_EQ(result[0], 2);
  EXPECT_EQ(result[1], 4);
  EXPECT_EQ(beam.getTotalSplits(), 1);
}

TEST(Beam_Tests, ShouldHandleSplitGoingOutOfBoundsLeft) {
  // Given
  std::string row = "S......";
  Beam beam(row);
  // When
  beam.moveDownward("^......");
  // Then
  auto result = beam.getCurrentBeamPositions();
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], 1);
  EXPECT_EQ(beam.getTotalSplits(), 1);
}

TEST(Beam_Tests, ShouldHandleSplitGoingOutOfBoundsRight) {
  // Given
  std::string row = "......S";
  Beam beam(row);
  // When
  beam.moveDownward("......^");
  // Then
  auto result = beam.getCurrentBeamPositions();
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], 5);
  EXPECT_EQ(beam.getTotalSplits(), 1);
}

TEST(Beam_Tests, ShouldMergeBeams) {
  // Given
  std::string row = "...S...";
  Beam beam(row);
  // When
  beam.moveDownward("...^...");
  beam.moveDownward("..^.^..");
  // Then
  auto result = beam.getCurrentBeamPositions();
  EXPECT_EQ(result.size(), 3);
  EXPECT_EQ(result[0], 1);
  EXPECT_EQ(result[1], 3);
  EXPECT_EQ(result[2], 5);
  EXPECT_EQ(beam.getTotalSplits(), 3);
}

TEST(Beam_Tests, ShouldFindTotalPaths) {
  // Given
  std::string row = "...S...";
  Beam beam(row);
  // When
  beam.moveDownward("...^...");
  // Then
  EXPECT_EQ(beam.getTotalPaths(), 2);
}

TEST(Beam_Tests, ShouldFindTotalPaths3) {
  // Given
  std::string row = "...S...";
  Beam beam(row);
  // When
  beam.moveDownward(".......");
  beam.moveDownward("...^...");
  beam.moveDownward("..^.^..");
  beam.moveDownward(".......");
  // Then
  EXPECT_EQ(beam.getTotalPaths(), 4);
}

TEST(Beam_Tests, ShouldFindTotalPathsWhenGoingOutOfBounds) {
  // Given
  std::string row = ".S......";
  Beam beam(row);
  // When
  beam.moveDownward(".....");
  beam.moveDownward(".^...");
  beam.moveDownward("^....");
  beam.moveDownward(".....");
  // Then
  EXPECT_EQ(beam.getTotalPaths(), 3);
}


TEST(Beam_Tests, ShouldRememberAllPaths_NoSplit) {
  // Given
  std::string row = "...S...";
  Beam beam(row);
  // When
  beam.moveDownward(".......");
  //beam.moveDownward("...^...");
  // Then
  EXPECT_EQ(beam.getTotalPaths(), 1);
}


TEST(Beam_Tests, ShouldRememberAllPaths_Split) {
  // Given
  std::string row = "...S...";
  Beam beam(row);
  // When
  beam.moveDownward(".......");
  beam.moveDownward("...^...");
  // Then
  EXPECT_EQ(beam.getTotalPaths(), 2);
}