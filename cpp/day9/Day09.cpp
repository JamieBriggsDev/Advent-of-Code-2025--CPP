//
// Created by Jamie Briggs on 09/12/2025.
//

#include "Day09.h"

#include <iostream>
#include <ostream>
#include <regex>

#include "../core/Pair.h"

namespace solutions {


  std::string Day09::solvePartOne(const helper::SolutionInput *input) {
    const regex listsRegex("([0-9]+),([0-9]+)");

    std::vector<core::Pair> coordinates;
    const int width = input->getTestInput()[0].size();
    const int height = input->getTestInput().size();
    for (const auto &row: input->getTestInput()) {
      smatch m;
      regex_search(row, m, listsRegex);
      const long x = std::stol(m[1]);
      const long y = std::stol(m[2]);
      coordinates.emplace_back(x, y);
    }

    // Just set to first pair to initialize.
    core::Pair* pairOne = nullptr;
    core::Pair* pairTwo = nullptr;
    long largestDistanceFound = 0;
    for (int firstIdx = 1; firstIdx < coordinates.size(); firstIdx++) {
      for (int secondIdx = firstIdx + 1; secondIdx < coordinates.size(); secondIdx++) {
        long dist = coordinates[firstIdx].areaBetween(coordinates[secondIdx]);
        if (dist > largestDistanceFound) {
          largestDistanceFound = dist;
          pairOne = &coordinates[firstIdx];
          pairTwo = &coordinates[secondIdx];
        }
      }
    }
    std::cout << "Largest distance found: " << largestDistanceFound << std::endl;
    std::cout << "Coordinates: " << pairOne->toString() << " and " << pairTwo->toString() << std::endl;

    return std::to_string(largestDistanceFound);
  }
  std::string Day09::solvePartTwo(const helper::SolutionInput *input) {

    return "Not solved";
  }
} // namespace solutions
