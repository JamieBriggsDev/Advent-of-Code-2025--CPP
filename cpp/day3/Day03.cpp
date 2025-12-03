//
// Created by Jamie Briggs on 03/12/2025.
//

#include "Day03.h"

#include "BatteryBank.h"

namespace solutions {

  string Day03::solvePartOne(const helper::SolutionInput *input) {
    std::vector<D3::BatteryBank> banks;
    for (const auto &row: input->getTestInput()) {
      banks.emplace_back(row);
    }

    int result = 0;
    for (const auto &bank: banks) {
      result += bank.getLargestJoltage();
    }
    return std::to_string(result);
  }

  string Day03::solvePartTwo(const helper::SolutionInput *input) {
    std::vector<D3::BatteryBank> banks;
    for (const auto &row: input->getTestInput()) {
      banks.emplace_back(row);
    }

    long long result = 0;
    for (const auto &bank: banks) {
      result += bank.getLargestJoltage(12);
    }
    return std::to_string(result);
  }

} // namespace solutions
