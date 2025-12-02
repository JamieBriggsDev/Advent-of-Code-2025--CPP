//
// Created by Jamie Briggs on 02/12/2025.
//

#include "Range.h"

namespace D2 {
  std::vector<long> Range::getFullRange() const {
    std::vector<long> result;
    for (long i = startId; i <= endId; i++) {
      result.push_back(i);
    }
    return result;
  }
} // namespace D2
