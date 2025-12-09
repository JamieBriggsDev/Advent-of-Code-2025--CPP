//
// Created by Jamie Briggs on 01/12/2024.
//

#ifndef PAIR_H
#define PAIR_H
#include <cmath>
#include <functional>
#include <set>
#include <string>

namespace core {

  class Pair {
  public:
    long long x = 0, y = 0;
    Pair() = default;
    Pair(long long a, long long b) : x(a), y(b) {}
    [[nodiscard]] long long distance() const {
      long long result = x - y;
      if (result < 0)
        result = -result;
      return result;
    }

    [[nodiscard]] long long manhattanDistance(const Pair &other) const {
      return std::abs(x - other.x) + std::abs(y - other.y);
    }
    [[nodiscard]] double heuristicDistance(const Pair &other) const {
      return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    bool setContainsPair(std::set<Pair> pairs) { return pairs.contains(core::Pair(x, y)); }

    long long areaBetween(const Pair &pair) {
      long long xResult = std::abs(x - pair.x) + 1;
      long long yResult = std::abs(y - pair.y) + 1;
      return xResult * yResult;
    }
    std::string toString() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ")"; }

    bool sitsInbetween(Pair second, Pair value) {
      // Check if sits inbetween the x axis
      if (this->x == second.x && this->x == value.x) {
        long long minY = std::min(this->y, second.y);
        long long maxY = std::max(this->y, second.y);
        return value.y >= minY && value.y <= maxY;
      }
      if (this->y == second.y && this->y == value.y) {
        long long minX = std::min(this->x, second.x);
        long long maxX = std::max(this->x, second.x);
        return value.x >= minX && value.x <= maxX;
      }
      return false;
    }

    std::vector<Pair> getAllPairsAcrossRange(Pair other) {
      std::vector<Pair> result;
      if (this->x == other.x) {
        long long minY = std::min(this->y, other.y);
        long long maxY = std::max(this->y, other.y);
        for (long long idxY = minY; idxY <= maxY; idxY++) {
          result.emplace_back(this->x, idxY);
        }
      } else if (this->y == other.y) {
        long long minX = std::min(this->x, other.x);
        long long maxX = std::max(this->x, other.x);
        for (long long idxX = minX; idxX <= maxX; idxX++) {
          result.emplace_back(idxX, this->y);
        }
      }
      return result;
    }

    bool operator==(const Pair &other) const { return (x == other.x) && (y == other.y); }
    Pair operator+(const Pair &other) const { return Pair(x + other.x, y + other.y); }
    void operator+=(const Pair &other) {
      x += other.x;
      y += other.y;
    }
    Pair operator-(const Pair &other) const { return Pair(x - other.x, y - other.y); }
    bool operator<(const Pair &other) const { return (x < other.x) || (x == other.x && y < other.y); }
    bool operator>(const Pair &other) const { return (x > other.x) || (x == other.x && y > other.y); }
  };

} // namespace core

// Hash specialization for core::Pair
namespace std {
  template<>
  struct hash<core::Pair> {
    std::size_t operator()(const core::Pair &p) const noexcept {
      // Simple hash combining using bitwise operators
      return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
  };
} // namespace std

#endif // PAIR_H
