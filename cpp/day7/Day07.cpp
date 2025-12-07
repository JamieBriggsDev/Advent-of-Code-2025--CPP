//
// Created by Jamie Briggs on 07/12/2025.
//

#include "Day07.h"

#include "Beam.h"

namespace solutions {


  std::string Day07::solvePartOne(const helper::SolutionInput *input) {
    auto rows = input->getTestInput();

    D7::Beam beam(rows[0]);
    for (int i = 1; i < rows.size(); i++) {
      beam.moveDownward(rows[i]);
    }

    return std::to_string(beam.getTotalSplits());
  }

  std::string Day07::solvePartTwo(const helper::SolutionInput *input) {
    auto rows = input->getTestInput();

    D7::Beam beam(rows[0]);
    for (int i = 1; i < rows.size(); i++) {
      beam.moveDownward(rows[i]);
    }

    return std::to_string(beam.getTotalPaths());
  }
} // namespace solutions
