//
// Created by Jamie Briggs on 07/12/2025.
//

#include "Beam.h"

#include <algorithm>

namespace D7 {

  Beam::Beam(std::string input) {
    int beamPosition = input.find('S');
    this->beamPositions_.push_back(std::vector{beamPosition});
  }

  std::vector<int> Beam::getBeamPositions(const int position) const { return this->beamPositions_[position]; }

  void Beam::moveDownward(std::string row) {
    int latestRowIndex{static_cast<int>(this->beamPositions_.size() - 1)};
    auto previousRow = this->beamPositions_[latestRowIndex];
    std::vector<int> newRow;
    for (int position: previousRow) {
      if (row[position] == '^') {
        this->totalSplits++;
        int totalChanges = 0;
        if (position > 0) {
          totalChanges++;
          newRow.push_back(position - 1);
        }
        if (position < row.length() - 1) {
          totalChanges++;
          newRow.push_back(position + 1);
        }

        if (totalChanges == 2) {
          this->totalPaths += 1;
        }
      } else {
        newRow.push_back(position);
      }
    }

      // Remove duplicate numbers from newRow
      std::sort(newRow.begin(), newRow.end());
      newRow.erase(std::unique(newRow.begin(), newRow.end()), newRow.end());

    beamPositions_.emplace_back(newRow);
  }
} // namespace D7
