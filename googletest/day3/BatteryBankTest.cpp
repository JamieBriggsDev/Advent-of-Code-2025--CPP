//
// Created by Jamie Briggs on 01/12/2025.
//

#include "../../cpp/day3/BatteryBank.h"
#include <gtest/gtest.h>

using namespace D3;

TEST(BatteryBank_Test, ShouldInitialize)
{
  // Given
  std::string bankString = "123";
  // When
  BatteryBank bank(bankString);
  // Then
  ASSERT_EQ(bank.getBatteries().size(), 3);
  ASSERT_EQ(bank.getBatteries()[0], 1);
  ASSERT_EQ(bank.getBatteries()[1], 2);
  ASSERT_EQ(bank.getBatteries()[2], 3);
}


TEST(BatteryBank_Test, GetLargestJoltage_ShouldFindFromTwoNumbers)
{
  // Given
  std::string bankString = "35";
  // When
  BatteryBank bank(bankString);
  // Then
  ASSERT_EQ(bank.getLargestJoltage(), 35);
}


TEST(BatteryBank_Test, GetLargestJoltage_ShouldFindFromFiveNumbers)
{
  // Given
  std::string bankString = "19234";
  // When
  BatteryBank bank(bankString);
  // Then
  ASSERT_EQ(bank.getLargestJoltage(), 94);
}


TEST(BatteryBank_Test, GetLargestJoltageWithParam3_ShouldFindFromFiveNumbers)
{
  // Given
  std::string bankString = "19234";
  // When
  BatteryBank bank(bankString);
  // Then
  ASSERT_EQ(bank.getLargestJoltage(3), 934);
}

TEST(BatteryBank_Test, GetLargestJoltageWithParam12_ShouldFindFromLargeExample)
{
  // Given
  std::string bankString = "987654321111111";
  // When
  BatteryBank bank(bankString);
  // Then
  ASSERT_EQ(bank.getLargestJoltage(12), 987654321111);
}


TEST(BatteryBank_Test, GetLargestJoltageWithParam12_ShouldFindFromLargeExampleTwo)
{
  // Given
  std::string bankString = "234234234234278";
  // When
  BatteryBank bank(bankString);
  // Then
  ASSERT_EQ(bank.getLargestJoltage(12), 434234234278);
}

