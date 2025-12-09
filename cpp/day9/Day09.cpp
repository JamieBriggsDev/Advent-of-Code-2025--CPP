//
// Created by Jamie Briggs on 09/12/2025.
//

#include "Day09.h"

#include <iostream>
#include <ostream>
#include <regex>

#include "../core/Pair.h"
#include "GreenTileFinder.h"

namespace solutions {


  std::string Day09::solvePartOne(const helper::SolutionInput *input) {

    std::vector<core::Pair> redTiles = createRedTiles(input->getTestInput());

    core::Pair *pairOne = nullptr;
    core::Pair *pairTwo = nullptr;
    long largestDistanceFound = 0;
    for (int firstIdx = 1; firstIdx < redTiles.size(); firstIdx++) {
      for (int secondIdx = firstIdx + 1; secondIdx < redTiles.size(); secondIdx++) {
        long dist = redTiles[firstIdx].areaBetween(redTiles[secondIdx]);
        if (dist > largestDistanceFound) {
          largestDistanceFound = dist;
          pairOne = &redTiles[firstIdx];
          pairTwo = &redTiles[secondIdx];
        }
      }
    }
    std::cout << "Largest distance found: " << largestDistanceFound << std::endl;
    std::cout << "Coordinates: " << pairOne->toString() << " and " << pairTwo->toString() << std::endl;

    return std::to_string(largestDistanceFound);
  }
  std::string Day09::solvePartTwo(const helper::SolutionInput *input) {
    std::vector<core::Pair> redTiles = createRedTiles(input->getTestInput());

    std::vector<D9::GreenTileBound> greenTileBounds = D9::GreenTileFinder::findGreenTiles(redTiles);

    core::Pair *pairOne = nullptr;
    core::Pair *pairTwo = nullptr;
    long largestDistanceFound = 0;
    for (int firstIdx = 0; firstIdx < redTiles.size(); firstIdx++) {
      for (int secondIdx = 0; secondIdx < redTiles.size(); secondIdx++) {
        if (firstIdx == secondIdx) {
          continue;
        }

        // Before continuing, check full surface is within bounds
        core::Pair firstCorner(redTiles[firstIdx].x, redTiles[secondIdx].y);
        core::Pair secondCorner(redTiles[secondIdx].x, redTiles[firstIdx].y);
        int minX = std::min(firstCorner.x, secondCorner.x);
        int maxX = std::max(firstCorner.x, secondCorner.x);
        int minY = std::min(firstCorner.y, secondCorner.y);
        int maxY = std::max(firstCorner.y, secondCorner.y);
        bool isValid = true;
        for (int x = minX; x <= maxX && isValid; x++) {
          for (int y = minY; y <= maxY && isValid; y++) {
            bool pairInBounds = false;
            for (const auto &greenTileBound: greenTileBounds) {
              if (greenTileBound.isWithinBounds(core::Pair(x, y))) {
                pairInBounds = true;
                break;
              }
            }

            if (!pairInBounds) {
              // Found a pair which doesn't have a green
              isValid = false;
              break;
            }
          }

        }

        if (!isValid) {
          continue;
        }
        if (long dist = redTiles[firstIdx].areaBetween(redTiles[secondIdx]); dist > largestDistanceFound) {
          largestDistanceFound = dist;
          pairOne = &redTiles[firstIdx];
          pairTwo = &redTiles[secondIdx];
        }
      }
    }
    std::cout << "Largest distance found: " << largestDistanceFound << std::endl;
    std::cout << "Coordinates: " << pairOne->toString() << " and " << pairTwo->toString() << std::endl;

    /**
     * Too Low
    Largest distance found: 162287760
Coordinates: (2243, 50262) and (94872, 48511)

  Part 2 solution: 162287760
  Part 2 took 430ms to solve
     */
    return std::to_string(largestDistanceFound);
  }
  std::vector<core::Pair> Day09::createRedTiles(const std::vector<std::string> &input) {
    std::vector<core::Pair> redTiles;
    const regex listsRegex("([0-9]+),([0-9]+)");
    for (const auto &row: input) {
      smatch m;
      regex_search(row, m, listsRegex);
      const long x = std::stol(m[1]);
      const long y = std::stol(m[2]);
      redTiles.emplace_back(x, y);
    }

    return redTiles;
  }


} // namespace solutions
