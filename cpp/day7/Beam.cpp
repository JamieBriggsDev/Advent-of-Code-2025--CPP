//
// Created by Jamie Briggs on 07/12/2025.
//

#include "Beam.h"

#include <algorithm>
#include <iostream>
#include <map>

namespace D7 {

  Beam::Beam(std::string input) {
    int beamPosition = input.find('S');
    this->beamPaths_.emplace_back(beamPosition, 1);
  }

  std::vector<int> Beam::getCurrentBeamPositions() const {
    std::vector<int> result;
    for (const auto &beamPath: beamPaths_) {
      if (!beamPath.hasOutOfBounds()) {
        result.emplace_back(beamPath.getCurrentPosition());
      }
    }

    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());

    return result;
  }

  void Beam::moveDownward(const std::string &row) {

    std::map<int, int> beamPathsToAdd_;

    std::string rowBeingMade = row;

    for (auto &beamPath: beamPaths_) {
      if (beamPath.hasOutOfBounds()) {
        continue;
      }


      if (int currentPosition = beamPath.getCurrentPosition(); row[currentPosition] == '^') {
        // This is used to find the answer to part 1
        this->totalSplits++;


        // Make current route keep left, and make new route via right direction
        if (currentPosition > 0) {
          rowBeingMade[currentPosition - 1] = '|';
          beamPath.setCurrentStep(currentPosition - 1);
        } else if (currentPosition == 0) {
          beamPath.setOutOfBounds(true);
        }

        // Go right
        if (currentPosition < row.length() - 1) {
          rowBeingMade[currentPosition + 1] = '|';
          beamPathsToAdd_.emplace(currentPosition + 1, beamPath.getTotalRoutesToCurrentStep());
        } else if (currentPosition == row.length()) {
          beamPath.setOutOfBounds(true);
        }

      } else {
        rowBeingMade[currentPosition] = '|';
        beamPath.setCurrentStep(currentPosition);
      }
    }


    // Add any new paths which were found, whilst merging duplicate current steps
    for (const auto &newPath: beamPathsToAdd_) {
      bool foundDuplicate = false;
      for (auto &existingPath: beamPaths_) {
        if (newPath.first == existingPath.getCurrentPosition()) {
          existingPath.addToTotalRoutesToCurrentStep(newPath.second);
          foundDuplicate = true;
        }
      }
      if (!foundDuplicate) {
        BeamPath newPathToAdd(newPath.first, newPath.second);
        beamPaths_.emplace_back(newPathToAdd);
      }
    }

    long total_paths = this->getTotalPaths();
    std::cout << rowBeingMade << " " << total_paths << std::endl;
  }
} // namespace D7
