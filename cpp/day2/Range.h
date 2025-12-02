//
// Created by Jamie Briggs on 02/12/2025.
//

#ifndef AOC2025_RANGE_H
#define AOC2025_RANGE_H
#include <vector>

namespace D2 {

  class Range {
    const long startId, endId;
    public:
    Range(long startId, long endId) : startId(startId), endId(endId) {}
    long getStartId() const { return startId; }
    long getEndId() const { return endId; }
    std::vector<long> getFullRange() const;
  };

} // namespace D2

#endif // AOC2025_RANGE_H
