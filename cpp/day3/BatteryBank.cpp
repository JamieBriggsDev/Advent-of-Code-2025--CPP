//
// Created by Jamie Briggs on 03/12/2025.
//

#include "BatteryBank.h"

namespace D3 {
  BatteryBank::BatteryBank(std::string batteries) {
    for (const auto &battery : batteries) {
      this->batteries_.push_back(battery - '0');
    }
  }
  int32_t BatteryBank::getLargestJoltage() const {
    // Find largest number which isn't last number as first digit can't be last
    int idxFirst = -1;
    for (int x = 0; x < batteries_.size() - 1; x++) {
      if (idxFirst == -1 || batteries_[idxFirst] < batteries_[x]) {
        idxFirst = x;
      }
    }

    // Find largest number after first number
    int idxSecond = -1;
    for (int x = idxFirst + 1; x < batteries_.size(); x++) {
      if (idxSecond == -1 || batteries_[idxSecond] < batteries_[x]) {
        idxSecond = x;
      }
    }

    int digitOne = batteries_[idxFirst] * 10;
    int digitTwo = batteries_[idxSecond];

    return digitOne + digitTwo;
  }
} // namespace D3
