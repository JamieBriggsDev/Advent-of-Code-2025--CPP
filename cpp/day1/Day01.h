//
// Created by Jamie Briggs on 01/12/2024.
//

#ifndef DAY_01_H
#define DAY_01_H

#include <memory>
#include <string>

#include "../Day.h"
#include "../helper/SolutionInput.h"
#include "Dial.h"

using namespace helper;

namespace solutions {
  class Day01 final : public Day {
  public:
    std::string solvePartOne(const helper::SolutionInput *input) override;
    static void moveDial(const helper::SolutionInput *input, unique_ptr<Day1::Dial> &dial);
    std::string solvePartTwo(const helper::SolutionInput *input) override;
  };
} // namespace solutions

#endif // DAY_01_H
