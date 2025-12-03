//
// Created by Jamie Briggs on 03/12/2025.
//

#include "BatteryBank.h"

#include <cmath>
#include <complex>
#include <iostream>

namespace D3 {
  int8_t BatteryBank::findIndexOfLargestNumberFromRange(int8_t startIdx, int8_t endIdx) const {
    int8_t largestIdx = startIdx;
    for (int8_t i = startIdx; i < endIdx; i++) {
      if (batteries_[i] > batteries_[largestIdx]) {
        largestIdx = i;
      }
    }
    return largestIdx;
  }
  BatteryBank::BatteryBank(std::string batteries) {
    for (const auto &battery: batteries) {
      this->batteries_.push_back(battery - '0');
    }
  }
  long long BatteryBank::getLargestJoltage() const { return getLargestJoltage(2); }
  long long BatteryBank::getLargestJoltage(int8_t totalBatteries) const {
    long long result = 0;
    int8_t mostLeftIdxFound = 0;
    for (uint8_t digitIdx = 0; digitIdx < totalBatteries; digitIdx++) {
      int digitMultiplier = totalBatteries - digitIdx;
      int foundIdx = findIndexOfLargestNumberFromRange(mostLeftIdxFound, batteries_.size() - digitMultiplier + 1);

      long batteryValue = batteries_[foundIdx];
      result += batteryValue * (std::pow(10, digitMultiplier - 1));
      mostLeftIdxFound = foundIdx + 1;
    }

    return result;
  }
} // namespace D3
