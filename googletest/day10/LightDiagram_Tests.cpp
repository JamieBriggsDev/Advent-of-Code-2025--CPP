//
// Created by Jamie Briggs on 10/12/2025.
//

#include <gtest/gtest.h>

#include "../../cpp/day10/ButtonSchematic.h"
#include "../../cpp/day10/LightDiagram.h"

using namespace D10;

TEST(LightDiagram_Tests, ShouldInitialize) {
  // Given
  std::string diagram = ".##.";
  // When
  LightDiagram lightDiagram(diagram);
  // Then
  ASSERT_FALSE(lightDiagram.getState()[0]);
  ASSERT_FALSE(lightDiagram.getState()[1]);
  ASSERT_FALSE(lightDiagram.getState()[2]);
  ASSERT_FALSE(lightDiagram.getState()[3]);
  ASSERT_FALSE(lightDiagram.getGoal()[0]);
  ASSERT_TRUE(lightDiagram.getGoal()[1]);
  ASSERT_TRUE(lightDiagram.getGoal()[2]);
  ASSERT_FALSE(lightDiagram.getGoal()[3]);
}

TEST(LightDiagram_Tests, ShouldInitializeWithJoltage) {
  // Given
  std::string diagram = ".##.";
  std::string joltage = "1,2,3,4";
  // When
  LightDiagram lightDiagram(diagram, joltage);
  // Then
  ASSERT_FALSE(lightDiagram.getState()[0]);
  ASSERT_FALSE(lightDiagram.getState()[1]);
  ASSERT_FALSE(lightDiagram.getState()[2]);
  ASSERT_FALSE(lightDiagram.getState()[3]);
  ASSERT_FALSE(lightDiagram.getGoal()[0]);
  ASSERT_TRUE(lightDiagram.getGoal()[1]);
  ASSERT_TRUE(lightDiagram.getGoal()[2]);
  ASSERT_FALSE(lightDiagram.getGoal()[3]);
  ASSERT_EQ(lightDiagram.getJoltageState()[0], 0);
  ASSERT_EQ(lightDiagram.getJoltageState()[1], 0);
  ASSERT_EQ(lightDiagram.getJoltageState()[2], 0);
  ASSERT_EQ(lightDiagram.getJoltageState()[3], 0);
  ASSERT_EQ(lightDiagram.getJoltageGoal()[0], 1);
  ASSERT_EQ(lightDiagram.getJoltageGoal()[1], 2);
  ASSERT_EQ(lightDiagram.getJoltageGoal()[2], 3);
  ASSERT_EQ(lightDiagram.getJoltageGoal()[3], 4);
}

TEST(LightDiagram_Tests, ShouldPressNoLights) {
  // Given
  std::string diagram = ".##.";
  LightDiagram lightDiagram(diagram);
  std::vector<uint8_t> pressedLights{};
  ButtonSchematic buttonSchematic(pressedLights);
  // When
  lightDiagram.pressButtons(buttonSchematic);
  // Then
  ASSERT_FALSE(lightDiagram.getState()[0]);
  ASSERT_FALSE(lightDiagram.getState()[1]);
  ASSERT_FALSE(lightDiagram.getState()[2]);
  ASSERT_FALSE(lightDiagram.getState()[3]);
  ASSERT_EQ(lightDiagram.getJoltageState()[0], 0);
  ASSERT_EQ(lightDiagram.getJoltageState()[1], 0);
  ASSERT_EQ(lightDiagram.getJoltageState()[2], 0);
  ASSERT_EQ(lightDiagram.getJoltageState()[3], 0);
  ASSERT_FALSE(lightDiagram.isValid());
}

TEST(LightDiagram_Tests, ShouldPressFirstLight) {
  // Given
  std::string diagram = ".##.";
  LightDiagram lightDiagram(diagram);
  std::vector<uint8_t> pressedLights{0};
  ButtonSchematic buttonSchematic(pressedLights);
  // When
  lightDiagram.pressButtons(buttonSchematic);
  // Then
  ASSERT_TRUE(lightDiagram.getState()[0]);
  ASSERT_FALSE(lightDiagram.getState()[1]);
  ASSERT_FALSE(lightDiagram.getState()[2]);
  ASSERT_FALSE(lightDiagram.getState()[3]);
  ASSERT_EQ(lightDiagram.getJoltageState()[0], 1);
  ASSERT_EQ(lightDiagram.getJoltageState()[1], 0);
  ASSERT_EQ(lightDiagram.getJoltageState()[2], 0);
  ASSERT_EQ(lightDiagram.getJoltageState()[3], 0);
  ASSERT_FALSE(lightDiagram.isValid());
}

TEST(LightDiagram_Tests, ShouldPressTwoLights) {
  // Given
  std::string diagram = ".##.";
  LightDiagram lightDiagram(diagram);
  std::vector<uint8_t> pressedLights{0,2};
  ButtonSchematic buttonSchematic(pressedLights);
  // When
  lightDiagram.pressButtons(buttonSchematic);
  // Then
  ASSERT_TRUE(lightDiagram.getState()[0]);
  ASSERT_FALSE(lightDiagram.getState()[1]);
  ASSERT_TRUE(lightDiagram.getState()[2]);
  ASSERT_FALSE(lightDiagram.getState()[3]);
  ASSERT_EQ(lightDiagram.getJoltageState()[0], 1);
  ASSERT_EQ(lightDiagram.getJoltageState()[1], 0);
  ASSERT_EQ(lightDiagram.getJoltageState()[2], 1);
  ASSERT_EQ(lightDiagram.getJoltageState()[3], 0);
  ASSERT_FALSE(lightDiagram.isValid());
}

TEST(LightDiagram_Tests, ShouldPressFourLights) {
  // Given
  std::string diagram = ".##.";
  LightDiagram lightDiagram(diagram);
  std::vector<uint8_t> pressedLights{0,1,2,3};
  ButtonSchematic buttonSchematic(pressedLights);
  // When
  lightDiagram.pressButtons(buttonSchematic);
  // Then
  ASSERT_TRUE(lightDiagram.getState()[0]);
  ASSERT_TRUE(lightDiagram.getState()[1]);
  ASSERT_TRUE(lightDiagram.getState()[2]);
  ASSERT_TRUE(lightDiagram.getState()[3]);
  ASSERT_EQ(lightDiagram.getJoltageState()[0], 1);
  ASSERT_EQ(lightDiagram.getJoltageState()[1], 1);
  ASSERT_EQ(lightDiagram.getJoltageState()[2], 1);
  ASSERT_EQ(lightDiagram.getJoltageState()[3], 1);
  ASSERT_FALSE(lightDiagram.isValid());
}

TEST(LightDiagram_Tests, ShouldPressLightsMultipleTimes) {
  // Given
  std::string diagram = ".##.";
  LightDiagram lightDiagram(diagram);
  std::vector<uint8_t> pressedLights{0,1,2,3};
  ButtonSchematic buttonSchematic(pressedLights);
  // When
  lightDiagram.pressButtons(buttonSchematic);
  lightDiagram.pressButtons(buttonSchematic);
  // Then
  ASSERT_FALSE(lightDiagram.getState()[0]);
  ASSERT_FALSE(lightDiagram.getState()[1]);
  ASSERT_FALSE(lightDiagram.getState()[2]);
  ASSERT_FALSE(lightDiagram.getState()[3]);
  ASSERT_EQ(lightDiagram.getJoltageState()[0], 2);
  ASSERT_EQ(lightDiagram.getJoltageState()[1], 2);
  ASSERT_EQ(lightDiagram.getJoltageState()[2], 2);
  ASSERT_EQ(lightDiagram.getJoltageState()[3], 2);
  ASSERT_FALSE(lightDiagram.isValid());
}

TEST(LightDiagram_Tests, ShouldPressButton_JoltageExample) {
  // Given
  std::string diagram = ".##.";
  std::string joltage = "3,5,4,7";
  LightDiagram lightDiagram(diagram, joltage);
  std::vector<uint8_t> pressedLights1{3};
  std::vector<uint8_t> pressedLights2{1,3};
  std::vector<uint8_t> pressedLights3{2,3};
  std::vector<uint8_t> pressedLights4{0,2};
  std::vector<uint8_t> pressedLights5{0,1};
  ButtonSchematic buttonSchematic(pressedLights1);
  ButtonSchematic buttonSchematic2(pressedLights2);
  ButtonSchematic buttonSchematic3(pressedLights3);
  ButtonSchematic buttonSchematic4(pressedLights4);
  ButtonSchematic buttonSchematic5(pressedLights5);
  // When
  lightDiagram.pressButtons(buttonSchematic);
  lightDiagram.pressButtons(buttonSchematic2);
  lightDiagram.pressButtons(buttonSchematic2);
  lightDiagram.pressButtons(buttonSchematic2);
  lightDiagram.pressButtons(buttonSchematic3);
  lightDiagram.pressButtons(buttonSchematic3);
  lightDiagram.pressButtons(buttonSchematic3);
  lightDiagram.pressButtons(buttonSchematic4);
  lightDiagram.pressButtons(buttonSchematic5);
  lightDiagram.pressButtons(buttonSchematic5);
  // Then
  ASSERT_EQ(lightDiagram.getJoltageState()[0], 3);
  ASSERT_EQ(lightDiagram.getJoltageState()[1], 5);
  ASSERT_EQ(lightDiagram.getJoltageState()[2], 4);
  ASSERT_EQ(lightDiagram.getJoltageState()[3], 7);
  ASSERT_TRUE(lightDiagram.isValidJoltage());

  // Check unbutton
  lightDiagram.unpressButtons(buttonSchematic);
  lightDiagram.unpressButtons(buttonSchematic2);
  lightDiagram.unpressButtons(buttonSchematic2);
  lightDiagram.unpressButtons(buttonSchematic2);
  lightDiagram.unpressButtons(buttonSchematic3);
  lightDiagram.unpressButtons(buttonSchematic3);
  lightDiagram.unpressButtons(buttonSchematic3);
  lightDiagram.unpressButtons(buttonSchematic4);
  lightDiagram.unpressButtons(buttonSchematic5);
  lightDiagram.unpressButtons(buttonSchematic5);
  ASSERT_EQ(lightDiagram.getJoltageState()[0], 0);
  ASSERT_EQ(lightDiagram.getJoltageState()[1], 0);
  ASSERT_EQ(lightDiagram.getJoltageState()[2], 0);
  ASSERT_EQ(lightDiagram.getJoltageState()[3], 0);
}

TEST(LightDiagram_Tests, ShouldBeInvalid) {
  // Given
  std::string diagram = ".##.";
  LightDiagram lightDiagram(diagram);
  // Then
  ASSERT_FALSE(lightDiagram.isValid());
}

TEST(LightDiagram_Tests, ShouldBeInvalidJoltage) {
  // Given
  std::string diagram = ".##.";
  std::string joltage = "0,1,1,0";
  LightDiagram lightDiagram(diagram, joltage);
  // Then
  ASSERT_FALSE(lightDiagram.isValidJoltage());
}

TEST(LightDiagram_Tests, ShouldBeValidIfTwoInnerOn) {
  // Given
  std::string diagram = ".##.";
  std::string joltage = "0,1,1,0";
  LightDiagram lightDiagram(diagram,joltage);
  std::vector<uint8_t> pressedLights{1,2};
  ButtonSchematic buttonSchematic(pressedLights);
  // When
  lightDiagram.pressButtons(buttonSchematic);
  // Then
  ASSERT_TRUE(lightDiagram.isValidJoltage());
}
