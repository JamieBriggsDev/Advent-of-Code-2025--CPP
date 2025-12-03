//
// Created by Jamie Briggs on 03/12/2025.
//

#ifndef AOC2025_BATTERY_H
#define AOC2025_BATTERY_H
#include <vector>

#ifdef __linux__
#include <cstdint>
#endif

namespace D3 {

  class BatteryBank {
    std::vector<int8_t> batteries_;
    int8_t findIndexOfLargestNumberFromRange(int8_t startIdx, int8_t endIdx) const;

  public:
    BatteryBank(std::string batteries);
    [[nodiscard]] std::vector<int8_t> &getBatteries() { return batteries_; };
    long long getLargestJoltage() const;
    long long getLargestJoltage(int8_t totalBatteries) const;
  };

} // namespace D3

#endif // AOC2025_BATTERY_H
