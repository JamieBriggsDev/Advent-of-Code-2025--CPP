//
// Created by Jamie Briggs on 01/12/2025.
//

#include "Dial.h"

#include <iostream>
#include <ostream>

namespace Day1 {
  void Dial::moveDial(const int16_t steps) {
    int16_t currentValue = value_;
    int16_t remainingSteps = steps;

    while (remainingSteps != 0) {
      // Add to current value for each step (Easier to track number of times touching zero)
      if (remainingSteps > 0) {
        currentValue++;
        remainingSteps--;
      } else {
        currentValue--;
        remainingSteps++;
      }

      // Keep current value within it's bounds
      if (currentValue > 99) {
        currentValue = 0;
      } else if (currentValue < 0) {
        currentValue = 99;
      }

      if (currentValue == 0) {
        totalTimesDialTouchesZeroDuringProcess_++;
      }
    }

    value_ = currentValue;


    if (value_ == 0) {
      totalTimesDialEndsOnZero_++;
    }
  }
} // namespace Day1
