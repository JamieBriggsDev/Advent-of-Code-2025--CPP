//
// Created by Jamie Briggs on 09/12/2025.
//

#ifndef AOC2025_GREENTILEFINDER_H
#define AOC2025_GREENTILEFINDER_H
#include "../core/Pair.h"

namespace D9 {

  struct GreenTileBound {
    core::Pair first;
    core::Pair second;
    core::Pair third;

    bool isWithinBounds(const core::Pair pair) const {
      long long minX = std::min({first.x, second.x, third.x});
      long long maxX = std::max({first.x, second.x, third.x});
      long long minY = std::min({first.y, second.y, third.y});
      long long maxY = std::max({first.y, second.y, third.y});

      return pair.x >= minX && pair.x <= maxX && pair.y >= minY && pair.y <= maxY;
    }
  };

  class GreenTileFinder {
  public:
    static core::Pair missingCorner(core::Pair first, core::Pair second, core::Pair third);
    static std::vector<GreenTileBound> findGreenTiles(const std::vector<core::Pair> &redTiles);

  };

} // namespace D9

#endif // AOC2025_GREENTILEFINDER_H
