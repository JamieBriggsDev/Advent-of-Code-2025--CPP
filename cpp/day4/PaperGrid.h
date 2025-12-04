//
// Created by Jamie Briggs on 04/12/2025.
//

#ifndef AOC2025_PAPERGRID_H
#define AOC2025_PAPERGRID_H
#include <iostream>

#include <ostream>
#include <utility>

#include "../core/Grid.h"

namespace D4 {

  class PaperGrid : public core::Grid<char> {
    char convertToObject(char c, int x, int y) override { return c; }

  public:
    explicit PaperGrid(std::vector<std::string> input) { this->init(std::move(input)); }

    int totalPaperSurrounding(const int x, const int y) {
      int result = 0;
      for (int xIdx = x - 1; xIdx <= x + 1; xIdx++) {
        for (int yIdx = y - 1; yIdx <= y + 1; yIdx++) {
          // Don't check current coord
          if (xIdx == x && yIdx == y) {
            continue;
          }
          // Don't check if index goes out of bounds
          if (xIdx < 0 || yIdx < 0 || xIdx >= this->getHorizontalLength() || yIdx >= this->getVerticalLength()) {
            continue;
          }
          if (this->getGrid()[yIdx][xIdx] == '@') {
            result++;
          }
        }
      }
      return result;
    }
  };

} // namespace D4

#endif // AOC2025_PAPERGRID_H
