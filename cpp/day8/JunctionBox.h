//
// Created by Jamie Briggs on 08/12/2025.
//

#ifndef AOC2025_JUNCTIONBOX_H
#define AOC2025_JUNCTIONBOX_H

#include <memory>
#include <regex>
#include <string>
#include <unordered_map>

using namespace std;

namespace D8 {

  class JunctionBox {
    long x_, y_, z_;
    std::vector<size_t> connectedJunctionBoxes_;

  public:
    JunctionBox(string input) {
      const regex listsRegex("([0-9]+),([0-9]+),([0-9]+)");
      smatch m;
      regex_search(input, m, listsRegex);

      x_ = stol(m[1]);
      y_ = stol(m[2]);
      z_ = stol(m[3]);
    }
    long getX() const { return x_; }
    long getY() const { return y_; }
    long getZ() const { return z_; }
    float getEuclideanDistance(const JunctionBox &other);

    void addConnectedJunctionBox(size_t index) { connectedJunctionBoxes_.push_back(index); }
    bool isConnectedToJunctionBox(size_t index) const {
      return std::find(connectedJunctionBoxes_.begin(), connectedJunctionBoxes_.end(), index) !=
             connectedJunctionBoxes_.end();
    }

    bool operator==(const JunctionBox &other) const { return x_ == other.x_ && y_ == other.y_ && z_ == other.z_; }
  };

} // namespace D8

#endif // AOC2025_JUNCTIONBOX_H
