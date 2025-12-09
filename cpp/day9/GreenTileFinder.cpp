//
// Created by Jamie Briggs on 09/12/2025.
//

#include "GreenTileFinder.h"

#include <unordered_set>

namespace D9 {


  core::Pair GreenTileFinder::missingCorner(core::Pair first, core::Pair second, core::Pair third) {
    std::array xs{first.x, second.x, third.x};
    std::array ys{first.y, second.y, third.y};

    long long x4;
    long long y4;

    // Find the x that appears exactly once
    if (xs[0] == xs[1]) {
      x4 = xs[2];
    } else if (xs[0] == xs[2]) {
      x4 = xs[1];
    } else {
      // xs[1] == xs[2] must be true in a valid rectangle
      x4 = xs[0];
    }

    // Find the y that appears exactly once
    if (ys[0] == ys[1]) {
      y4 = ys[2];
    } else if (ys[0] == ys[2]) {
      y4 = ys[1];
    } else {
      // ys[1] == ys[2] must be true in a valid rectangle
      y4 = ys[0];
    }

    return core::Pair{x4, y4};
  }
  std::vector<GreenTileBound> GreenTileFinder::findGreenTiles(const std::vector<core::Pair> &redTiles) {
    std::vector<GreenTileBound> result;

    // First find possible green tiles via edges of grid
    std::unordered_set<core::Pair> uniqueRedTiles;
    for (int i = 0; i < redTiles.size(); i++) {
      core::Pair first = redTiles[i];
      core::Pair second = redTiles[i+1 == redTiles.size() ? 0 : i+1];
      std::vector<core::Pair> allAcrossRange = first.getAllPairsAcrossRange(second);
      uniqueRedTiles.insert(allAcrossRange.begin(), allAcrossRange.end());
    }

    for (int i = 0; i < redTiles.size(); i++) {
      core::Pair first = redTiles[i];
      core::Pair second = redTiles[i+1 >= redTiles.size() ? i+1-redTiles.size() : i+1];
      core::Pair third = redTiles[i+2 >= redTiles.size() ? i+2-redTiles.size() : i+2];
      // Create artificial pair to complete square
      core::Pair fourth = missingCorner(first, second, third);

      bool fourthInBounds = uniqueRedTiles.find(fourth) != uniqueRedTiles.end();
      // If fourth is in the unique red tiles range
      if (fourthInBounds) {
        result.emplace_back(first, second, third);
      }
    }

    return result;
  }

} // namespace D9
