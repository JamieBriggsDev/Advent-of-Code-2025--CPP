//
// Created by Jamie Briggs on 03/12/2025.
//

#ifndef AOC2025_DAY04_H
#define AOC2025_DAY04_H
#include "../Day.h"
#include "PaperGrid.h"

namespace solutions {

  class Day04 final : public Day {
  public:
    std::string solvePartOne(const helper::SolutionInput *input) override;
    static std::vector<core::Pair> findMovablePaper(D4::PaperGrid paper_grid);
    std::string solvePartTwo(const helper::SolutionInput *input) override;
  };

} // namespace solutions

#endif // AOC2025_DAY04_H
