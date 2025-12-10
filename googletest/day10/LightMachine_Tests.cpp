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
  ASSERT_EQ(lightMachine.getDiagram().getJoltageGoal()[0], 3);
  ASSERT_EQ(lightMachine.getDiagram().getJoltageGoal()[1], 5);
  ASSERT_EQ(lightMachine.getDiagram().getJoltageGoal()[2], 4);
  ASSERT_EQ(lightMachine.getDiagram().getJoltageGoal()[3], 7);
  ASSERT_EQ(6, lightMachine.getButtonSchematics().size());
  // Just check first button, tests exist for button initialization
  ASSERT_EQ(1, lightMachine.getButtonSchematics()[0].getButtons().size());
  ASSERT_EQ(3, lightMachine.getButtonSchematics()[0].getButtons()[0]);
  // Check last button schematic is the longer one, should be sorted by total buttons
  ASSERT_EQ(3, lightMachine.getButtonSchematics()[5].getButtons().size());
}


TEST(LightMachine_Tests, ShouldFindFewestTotalPressesWithOneNumber) {
  // Given
  std::string input = "[#] (0) {0}";
  const D10::LightMachine lightMachine(input);
  // When
  auto result = lightMachine.findFewestPresses();
  // Then
  ASSERT_EQ(result.size(), 1);
  ASSERT_EQ(result[0], 0);
}

TEST(LightMachine_Tests, ShouldFindFewestTotalPressesWithOneNumberMoreInput) {
  // Given
  std::string input = "[.#.] (0) (1) (0) {0,1,2}";
  const D10::LightMachine lightMachine(input);
  // When
  auto result = lightMachine.findFewestPresses();
  // Then
  ASSERT_EQ(result.size(), 1);
  ASSERT_EQ(result[0], 1);
}

TEST(LightMachine_Tests, ShouldFindFewestTotalPressesWithOneNumberLongerNumbers) {
  // Given
  std::string input = "[.#.#] (0) (1,2) (0) (1,3) {1,2,3,4}";
  const D10::LightMachine lightMachine(input);
  // When
  auto result = lightMachine.findFewestPresses();
  // Then
  ASSERT_EQ(result.size(), 1);
  ASSERT_EQ(result[0], 3);
}

TEST(LightMachine_Tests, ShouldFindFewestTotalPressesWithTwoNumbers) {
  // Given
  std::string input = "[##] (0) (1) {1,2}";
  const D10::LightMachine lightMachine(input);
  // When
  auto result = lightMachine.findFewestPresses();
  // Then
  ASSERT_EQ(result.size(), 2);
  ASSERT_EQ(result[0], 0);
  ASSERT_EQ(result[1], 1);
}

TEST(LightMachine_Tests, ShouldFindFewestExampleOne) {
  // Given
  std::string input = "[.##.] (3) (1,3) (2) (2,3) (0,2) (0,1) {1,2,3,4}";
  const D10::LightMachine lightMachine(input);
  // When
  auto result = lightMachine.findFewestPresses();
  // Then
  ASSERT_EQ(result.size(), 2);
  ASSERT_EQ(result[0], 2);
  ASSERT_EQ(result[1], 3);
}

TEST(LightMachine_Tests, ShouldFindFewestExampleTwo) {
  // Given
  std::string input = "[...#.] (0,2,3,4) (2,3) (0,4) (0,1,2) (1,2,3,4) {7,5,12,7,2}";
  const D10::LightMachine lightMachine(input);
  // When
  auto result = lightMachine.findFewestPresses();
  // Then
  ASSERT_EQ(result.size(), 3);
  auto one = lightMachine.getButtonSchematics()[result[0]];
  auto two = lightMachine.getButtonSchematics()[result[1]];
  auto three = lightMachine.getButtonSchematics()[result[2]];
  ASSERT_EQ(result[0], 1);
  ASSERT_EQ(result[1], 2);
  ASSERT_EQ(result[2], 4);
}

TEST(LightMachine_Tests, ShouldFindFewestJoltageExampleOne) {
  // Given
  std::string input = "[.##.] (3) (1,3) (2) (2,3) (0,2) (0,1) {3,5,4,7}";
  const D10::LightMachine lightMachine(input);
  // When
  auto result = lightMachine.findFewestJoltagePresses();
  // Then
  ASSERT_EQ(result.size(), 10);
  ASSERT_EQ(result[0], 2);
  ASSERT_EQ(result[1], 3);
}
