//
// Created by Jamie Briggs on 08/12/2025.
//

#ifndef AOC2025_DAY08_H
#define AOC2025_DAY08_H
#include "../Day.h"
#include "Circuits.h"

namespace solutions {

  class Day08 final : public Day{
    int totalConnections;
    D8::Circuits* circuits_p = nullptr;
  public:
    Day08(int totalConnections) : totalConnections(totalConnections) {}
    std::string solvePartOne(const helper::SolutionInput *input) override;
    std::string solvePartTwo(const helper::SolutionInput *input) override;
  };

} // namespace solutions

#endif // AOC2025_DAY08_H
