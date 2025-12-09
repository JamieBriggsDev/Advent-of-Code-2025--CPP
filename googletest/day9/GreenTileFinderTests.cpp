//
// Created by Jamie Briggs on 09/12/2025.
//

#include <gtest/gtest.h>

#include "../../cpp/core/Pair.h"
#include "../../cpp/day9/GreenTileFinder.h"


TEST(GreenTileFinder_Tests, ShouldNotFindBoundFromNoRedTiles) {
  // Given
  std::vector<core::Pair> redTiles = {};
  // When
  auto result = D9::GreenTileFinder::findGreenTiles(redTiles);
  // Then
  ASSERT_EQ(result.size(), 0);
}

TEST(GreenTileFinder_Tests, ShouldNotFindBoundWithOnlyThreeRedTiles) {
  // Given
  std::vector<core::Pair> redTiles = {
    core::Pair(0,0),
    core::Pair(0,1),
    core::Pair(1,1)
  };
  // When
  auto result = D9::GreenTileFinder::findGreenTiles(redTiles);
  // Then
  ASSERT_EQ(result.size(), 0);
}

TEST(GreenTileFinder_Tests, ShouldFindBoundWithSquare) {
  // Given
  std::vector<core::Pair> redTiles = {
    core::Pair(0,0),
    core::Pair(0,1),
    core::Pair(1,1),
    core::Pair(1,0)
  };
  // When
  auto result = D9::GreenTileFinder::findGreenTiles(redTiles);
  // Then
  ASSERT_EQ(result.size(), 2);
}

TEST(GreenTileFinder_Tests, ShouldFindBoundWithLargerRectangle) {
  // Given
  /**
   X     X

   X  X  X
   */
  std::vector<core::Pair> redTiles = {
    core::Pair(0,0),
    core::Pair(0,1),
    core::Pair(1,1),
    core::Pair(2,1),
    core::Pair(2,0),
  };
  // When
  auto result = D9::GreenTileFinder::findGreenTiles(redTiles);
  // Then
  ASSERT_EQ(result.size(), 3);
}

TEST(GreenTileFinder_Tests, ShouldFindBoundWithLargerRectangleComplex) {
  // Given
  /**
   X     X



   X  X

      X  X
   */
  std::vector<core::Pair> redTiles = {
    core::Pair(0,0),
    core::Pair(5,0),
    core::Pair(5,10),
    core::Pair(3,10),
    core::Pair(3,6),
    core::Pair(0,6),
  };
  // When
  auto result = D9::GreenTileFinder::findGreenTiles(redTiles);
  // Then
  ASSERT_EQ(result.size(), 2);
}