//
// Created by Jamie Briggs on 03/12/2025.
//

#ifndef AOC2025_BATTERY_H
#define AOC2025_BATTERY_H
#include <vector>

namespace D3 {

  class BatteryBank {
    std::vector<int8_t> batteries_;
  public:
    BatteryBank(std::string batteries);
    [[nodiscard]] std::vector<int8_t> &getBatteries() {
      return batteries_;
    };
    int32_t getLargestJoltage() const;
  };

} // namespace D3

#endif // AOC2025_BATTERY_H
