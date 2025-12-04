//
// Created by Jamie Briggs on 03/12/2025.
//

#include "Day04.h"

#include "PaperGrid.h"

namespace solutions {

  string Day04::solvePartOne(const helper::SolutionInput *input) {
    D4::PaperGrid paper_grid(input->getTestInput());

    auto coords = findMovablePaper(paper_grid);

    return std::to_string(coords.size());
  }


  string Day04::solvePartTwo(const helper::SolutionInput *input) {
    D4::PaperGrid paper_grid(input->getTestInput());

    bool stillPaperToMove = true;

    int result = 0;
    while (stillPaperToMove) {
      auto coords = findMovablePaper(paper_grid);
      if (!coords.empty()) {
        result += coords.size();
        for (const auto &coord: coords) {
          paper_grid.getGrid()[coord.y][coord.x] = '.';
        }
        coords.clear();
      } else {
        stillPaperToMove = false;
      }
    }
    return std::to_string(result);
  }

  std::vector<core::Pair> Day04::findMovablePaper(D4::PaperGrid paper_grid) {
    std::vector<core::Pair> coords;

    // Loop through all of grid
    for (int x = 0; x < paper_grid.getHorizontalLength(); x++) {
      for (int y = 0; y < paper_grid.getVerticalLength(); y++) {
        if (paper_grid.getGrid()[y][x] == '@') {
          int total_paper_surrounding = paper_grid.totalPaperSurrounding(x, y);
          if (total_paper_surrounding < 4) {
            coords.emplace_back(x, y);
          }
        }
      }
    }

    return coords;
  }

} // namespace solutions
