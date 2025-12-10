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
  ASSERT_FALSE(lightDiagram.isValid());
}

TEST(LightDiagram_Tests, ShouldBeInvalid) {
  // Given
  std::string diagram = ".##.";
  LightDiagram lightDiagram(diagram);
  // Then
  ASSERT_FALSE(lightDiagram.isValid());
}

TEST(LightDiagram_Tests, ShouldBeValidIfTwoInnerOn) {
  // Given
  std::string diagram = ".##.";
  LightDiagram lightDiagram(diagram);
  std::vector<uint8_t> pressedLights{1,2};
  ButtonSchematic buttonSchematic(pressedLights);
  // When
  lightDiagram.pressButtons(buttonSchematic);
  // Then
  ASSERT_TRUE(lightDiagram.isValid());
}