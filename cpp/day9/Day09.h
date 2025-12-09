//
// Created by Jamie Briggs on 09/12/2025.
//

#ifndef AOC2025_DAY09_H
#define AOC2025_DAY09_H
#include "../Day.h"
#include "../core/Pair.h"

namespace solutions {

  class Day09 final : public Day {
  public:
    std::string solvePartOne(const helper::SolutionInput *input) override;
    std::string solvePartTwo(const helper::SolutionInput *input) override;
    static std::vector<core::Pair> createRedTiles(const std::vector<std::string> &input);
  };

} // namespace solutions

#endif // AOC2025_DAY09_H
