//
// Created by Jamie Briggs on 02/12/2025.
//

#include "../core/Range.h"

#include <iostream>

#include "AocException.h"

namespace core {
  std::vector<long> Range::getFullRange() const {
    std::vector<long> result;
    result.reserve(endId - startId + 1);
    for (long i = startId; i <= endId; i++) {
      result.push_back(i);
    }
    return result;
  }
  bool Range::isInRange(long id) const { return id >= startId && id <= endId; }
  void Range::compressUsingRange(const Range &range) {
    bool isStartInRange = range.isInRange(this->getStartId());
    bool isEndInRange = range.isInRange(this->getEndId());
    if (isStartInRange && isEndInRange) {
      //std::cout << "Range " << this->toString() << " is fully contained within " << range.toString() << std::endl;
      this->invalid = true;
    }
    // Move start date if sits within range
    else if (isStartInRange) {
      this->startId = range.getEndId() + 1;
    }
    // Move end date back if sits within range
    else if (isEndInRange) {
      this->endId = range.getStartId() - 1;
    }

  }
} // namespace core
