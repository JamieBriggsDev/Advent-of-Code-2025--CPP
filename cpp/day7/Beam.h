//
// Created by Jamie Briggs on 07/12/2025.
//

#ifndef AOC2025_BEAM_H
#define AOC2025_BEAM_H
#include <string>
#include <vector>

namespace D7 {

  class Beam {
    std::vector<std::vector<int>> beamPositions_;
    int totalSplits = 0;
    int totalPaths = 1; // Start with 1 path from the beginning
  public:
    Beam(std::string input);

    [[nodiscard]] int getTotalSplits() const {
      return totalSplits;
    }
    [[nodiscard]] int getTotalPaths() const {
      return totalPaths;
    }
    [[nodiscard]] std::vector<int> getBeamPositions(int position) const;
    void moveDownward(std::string row);
  };

} // namespace D7

#endif // AOC2025_BEAM_H
