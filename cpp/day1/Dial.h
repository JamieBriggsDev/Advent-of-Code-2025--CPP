//
// Created by Jamie Briggs on 01/12/2025.
//

#ifndef AOC2025_DIAL_H
#define AOC2025_DIAL_H
#include <cstdint>

namespace Day1 {

  class Dial {
    int16_t value_;
    int16_t totalTimesDialEndsOnZero_ = 0;
    int16_t totalTimesDialTouchesZeroDuringProcess_ = 0;
  public:
    explicit Dial(uint8_t value) : value_(value) {}
    [[nodiscard]] uint16_t getValue() const {
      return value_;
    }
    [[nodiscard]] uint16_t getTotalTimesDialEndsOnZero() const {
      return totalTimesDialEndsOnZero_;
    }
    [[nodiscard]] uint16_t getTotalTimesDialTouchesZero() const {
      return totalTimesDialTouchesZeroDuringProcess_;
    }

    void moveDial(int16_t steps);
  };

} // namespace Day1

#endif // AOC2025_DIAL_H
