//
// Created by Jamie Briggs on 02/12/2025.
//

#include "../core/Range.h"

#include <iostream>

namespace core {
  std::vector<long> Range::getFullRange() const {
    std::vector<long> result;
    result.reserve(endId - startId + 1);
    for (long i = startId; i <= endId; i++) {
      result.push_back(i);
    }
    return result;
  }
  bool Range::isInRange(long id) const { return id >= startId && id <= endId;
  }
} // namespace D2
