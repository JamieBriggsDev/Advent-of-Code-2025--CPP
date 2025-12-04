//
// Created by Jamie Briggs on 04/12/2025.
//

#include "../../cpp/day4/PaperGrid.h"
#include "../testHelper/InputUtils.h"
#include "gtest/gtest.h"

using namespace std;

class PaperGridTestFixture : public ::testing::Test {
protected:
  void SetUp() override {
    // Setup
    input = InputUtils::convertToVector(rawInput);
    secondInput = InputUtils::convertToVector(rawSecondInput);
  }

  void TearDown() override {
    // Tear down
    input.clear();
    secondInput.clear();
  }

  string rawInput =
    "...\n"
    ".@.\n"
    "...\n";
  vector<string> input;

  string rawSecondInput =
    "@..@...\n"
    "...@...\n"
    "...@...\n"
    "...@..@\n";
  vector<string> secondInput;
};

TEST_F(PaperGridTestFixture, ShouldInitializeGrid) {
  // Given
  // When
  D4::PaperGrid warehouse(input);
  // Then
  ASSERT_EQ(3, warehouse.getVerticalLength());
  ASSERT_EQ(3, warehouse.getHorizontalLength());
  ASSERT_EQ('.', warehouse.getGrid()[0][0]);
  ASSERT_EQ('.', warehouse.getGrid()[0][1]);
  ASSERT_EQ('.', warehouse.getGrid()[0][2]);
  ASSERT_EQ('.', warehouse.getGrid()[1][0]);
  ASSERT_EQ('@', warehouse.getGrid()[1][1]);
  ASSERT_EQ('.', warehouse.getGrid()[1][2]);
  ASSERT_EQ('.', warehouse.getGrid()[2][0]);
  ASSERT_EQ('.', warehouse.getGrid()[2][1]);
  ASSERT_EQ('.', warehouse.getGrid()[2][2]);
}

TEST_F(PaperGridTestFixture, ShouldInitializeLargerGrid) {
  // Given
  // When
  D4::PaperGrid warehouse(secondInput);
  // Then
  ASSERT_EQ(4, warehouse.getVerticalLength());
  ASSERT_EQ(7, warehouse.getHorizontalLength());
  ASSERT_EQ('@', warehouse.getGrid()[0][0]);
  ASSERT_EQ('.', warehouse.getGrid()[0][1]);
  ASSERT_EQ('.', warehouse.getGrid()[0][2]);
  ASSERT_EQ('@', warehouse.getGrid()[0][3]);
  ASSERT_EQ('.', warehouse.getGrid()[0][4]);
  ASSERT_EQ('.', warehouse.getGrid()[0][5]);
  ASSERT_EQ('.', warehouse.getGrid()[0][6]);
}

TEST_F(PaperGridTestFixture, ShouldReturnNoPaperSurrounding) {
  // Given
  string rawInput =
    "...\n"
    ".@.\n"
    "...\n";
  D4::PaperGrid warehouse(InputUtils::convertToVector(rawInput));
  // When
  auto result = warehouse.totalPaperSurrounding(1,1);
  // Then
  ASSERT_EQ(0, result);
}

TEST_F(PaperGridTestFixture, ShouldReturnOne) {
  // Given
  string rawInput =
    "@..\n"
    ".@.\n"
    "...\n";
  D4::PaperGrid warehouse(InputUtils::convertToVector(rawInput));
  // When
  auto result = warehouse.totalPaperSurrounding(1,1);
  // Then
  ASSERT_EQ(1, result);
}

TEST_F(PaperGridTestFixture, ShouldReturnTwo) {
  // Given
  string rawInput =
    "@..\n"
    ".@.\n"
    "..@\n";
  D4::PaperGrid warehouse(InputUtils::convertToVector(rawInput));
  // When
  auto result = warehouse.totalPaperSurrounding(1,1);
  // Then
  ASSERT_EQ(2, result);
}

TEST_F(PaperGridTestFixture, ShouldReturnThree) {
  // Given
  string rawInput =
    "@..\n"
    ".@@\n"
    "..@\n";
  D4::PaperGrid warehouse(InputUtils::convertToVector(rawInput));
  // When
  auto result = warehouse.totalPaperSurrounding(1,1);
  // Then
  ASSERT_EQ(3, result);
}

TEST_F(PaperGridTestFixture, ShouldReturnFour) {
  // Given
  string rawInput =
    "@@.\n"
    ".@@\n"
    "..@\n";
  D4::PaperGrid warehouse(InputUtils::convertToVector(rawInput));
  // When
  auto result = warehouse.totalPaperSurrounding(1,1);
  // Then
  ASSERT_EQ(4, result);
}

TEST_F(PaperGridTestFixture, ShouldReturnFive) {
  // Given
  string rawInput =
    "@@@\n"
    ".@@\n"
    "..@\n";
  D4::PaperGrid warehouse(InputUtils::convertToVector(rawInput));
  // When
  auto result = warehouse.totalPaperSurrounding(1,1);
  // Then
  ASSERT_EQ(5, result);
}

TEST_F(PaperGridTestFixture, ShouldReturnSix) {
  // Given
  string rawInput =
    "@@@\n"
    "@@@\n"
    "..@\n";
  D4::PaperGrid warehouse(InputUtils::convertToVector(rawInput));
  // When
  auto result = warehouse.totalPaperSurrounding(1,1);
  // Then
  ASSERT_EQ(6, result);
}

TEST_F(PaperGridTestFixture, ShouldReturnSeven) {
  // Given
  string rawInput =
    "@@@\n"
    "@@@\n"
    ".@@\n";
  D4::PaperGrid warehouse(InputUtils::convertToVector(rawInput));
  // When
  auto result = warehouse.totalPaperSurrounding(1,1);
  // Then
  ASSERT_EQ(7, result);
}

TEST_F(PaperGridTestFixture, ShouldReturnEight) {
  // Given
  string rawInput =
    "@@@\n"
    "@@@\n"
    "@@@\n";
  D4::PaperGrid warehouse(InputUtils::convertToVector(rawInput));
  // When
  auto result = warehouse.totalPaperSurrounding(1,1);
  // Then
  ASSERT_EQ(8, result);
}

TEST_F(PaperGridTestFixture, ShouldHandleNW) {
  // Given
  string rawInput =
    "@..\n"
    ".@.\n"
    "...\n";
  D4::PaperGrid warehouse(InputUtils::convertToVector(rawInput));
  // When
  auto result = warehouse.totalPaperSurrounding(0,0);
  // Then
  ASSERT_EQ(1, result);
}

TEST_F(PaperGridTestFixture, ShouldHandleNE) {
  // Given
  string rawInput =
    "..@\n"
    ".@.\n"
    "...\n";
  D4::PaperGrid warehouse(InputUtils::convertToVector(rawInput));
  // When
  auto result = warehouse.totalPaperSurrounding(2,0);
  // Then
  ASSERT_EQ(1, result);
}

TEST_F(PaperGridTestFixture, ShouldHandleSW) {
  // Given
  string rawInput =
    "...\n"
    ".@.\n"
    "@..\n";
  D4::PaperGrid warehouse(InputUtils::convertToVector(rawInput));
  // When
  auto result = warehouse.totalPaperSurrounding(0,2);
  // Then
  ASSERT_EQ(1, result);
}

TEST_F(PaperGridTestFixture, ShouldHandleSE) {
  // Given
  string rawInput =
    "...\n"
    ".@.\n"
    "..@\n";
  D4::PaperGrid warehouse(InputUtils::convertToVector(rawInput));
  // When
  auto result = warehouse.totalPaperSurrounding(2,2);
  // Then
  ASSERT_EQ(1, result);
}