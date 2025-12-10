//
// Created by Jamie Briggs on 10/12/2025.
//

#include <gtest/gtest.h>

#include "../../cpp/day10/LightMachine.h"

TEST(LightMachine_Tests, ShouldInitializeWithoutJoltage) {
  // Given
  std::string input = "[.##.] (3) (1,3) (2) (2,3,3) (0,2) (0,1) {3,5,4,7}";
  // When
  const D10::LightMachine lightMachine(input);
  // Then
  ASSERT_FALSE(lightMachine.getDiagram().getGoal()[0]);
  ASSERT_TRUE(lightMachine.getDiagram().getGoal()[1]);
  ASSERT_TRUE(lightMachine.getDiagram().getGoal()[2]);
  ASSERT_FALSE(lightMachine.getDiagram().getGoal()[3]);
  ASSERT_EQ(6, lightMachine.getButtonSchematics().size());
  // Just check first button, tests exist for button initialization
  ASSERT_EQ(1, lightMachine.getButtonSchematics()[0].getButtons().size());
  ASSERT_EQ(3, lightMachine.getButtonSchematics()[0].getButtons()[0]);
  // Check last button schematic is the longer one, should be sorted by total buttons
  ASSERT_EQ(3, lightMachine.getButtonSchematics()[5].getButtons().size());
}

// TODO Test initialize with joltage for part 2