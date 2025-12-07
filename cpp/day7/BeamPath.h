//
// Created by Jamie Briggs on 07/12/2025.
//

#ifndef AOC2025_BEAMPATH_H
#define AOC2025_BEAMPATH_H

namespace D7 {
  class BeamPath final {
    int pathRoute;
    bool hasGoneOutOfBounds = false;
    long totalRoutesToCurrentStep;

  public:
    explicit BeamPath(const int initial, const long totalRoutesToPoint) : pathRoute(initial), totalRoutesToCurrentStep(totalRoutesToPoint) {};
    explicit BeamPath() {};

    void setCurrentStep(const int step) { pathRoute = step; }

    [[nodiscard]] bool hasOutOfBounds() const { return hasGoneOutOfBounds; }
    void setOutOfBounds(const bool value) { hasGoneOutOfBounds = value; }

    void addToTotalRoutesToCurrentStep(const long value) {
      totalRoutesToCurrentStep += value;
    }
    long getTotalRoutesToCurrentStep() const { return totalRoutesToCurrentStep; }

    [[nodiscard]] int getCurrentPosition() const { return pathRoute; }
  };
} // namespace D7

#endif // AOC2025_BEAMPATH_H
