//
// Created by Jamie Briggs on 07/12/2025.
//

#ifndef AOC2025_BEAM_H
#define AOC2025_BEAM_H
#include <string>
#include <vector>

#include "BeamPath.h"

namespace D7 {

  class Beam {
    // Remembers all posible beam positions
    std::vector<std::vector<int>> beamPositions_;
    // Remembers all possible paths for the beam
    std::vector<BeamPath> beamPaths_;
    int totalSplits = 0;
  public:
    Beam(std::string input);

    [[nodiscard]] int getTotalSplits() const {
      return totalSplits;
    }

    [[nodiscard]] long getTotalPaths() const {
      long totalPaths = 0;
      for (const auto &beamPath : beamPaths_) {
        long total_routes_to_current_step = beamPath.getTotalRoutesToCurrentStep();
        totalPaths += total_routes_to_current_step;
      }
      return totalPaths;
    }

    [[nodiscard]] std::vector<int> getCurrentBeamPositions() const;
    void moveDownward(const std::string &row);
  };

} // namespace D7

#endif // AOC2025_BEAM_H
