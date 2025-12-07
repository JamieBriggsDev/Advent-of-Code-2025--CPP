//
// Created by Jamie Briggs on 02/12/2025.
//

#ifndef AOC2025_RANGE_H
#define AOC2025_RANGE_H
#include <iostream>
#include <string>
#include <vector>

#include "AocException.h"

namespace core {

  class Range {
    long startId, endId;
    bool invalid = false;
    public:
    Range(const long startId, const long endId) : startId(startId), endId(endId) {
    }
    [[nodiscard]] long getStartId() const { return startId; }
    [[nodiscard]] long getEndId() const { return endId; }
    [[nodiscard]] bool getInvalid() const { return invalid; }
    [[nodiscard]] std::vector<long> getFullRange() const;
    [[nodiscard]] bool isInRange(long id) const;
  public:
    void compressUsingRange(const Range &range);
    [[nodiscard]] std::string toString() const {
      return "Range[" + std::to_string(startId) + "-" + std::to_string(endId) + "]";
    }
  };

} // namespace D2

#endif // AOC2025_RANGE_H
