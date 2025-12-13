//
// Created by Jamie Briggs on 10/12/2025.
//

#include <gtest/gtest.h>

#include "../../cpp/day10/ButtonSchematic.h"

TEST(ButtonSchematic_Tests, ShouldInitialize) {
  // Given
  std::string diagram = "1,2,3";
  // When
  D10::ButtonSchematic schematic(diagram);
  // Then
  ASSERT_EQ(1, schematic.getButtons()[0]);
  ASSERT_EQ(2, schematic.getButtons()[1]);
  ASSERT_EQ(3, schematic.getButtons()[2]);
}