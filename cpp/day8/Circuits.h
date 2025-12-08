//
// Created by Jamie Briggs on 08/12/2025.
//

#ifndef AOC2025_CIRCUITS_H
#define AOC2025_CIRCUITS_H
#include <vector>

#include "../core/Pair.h"
#include "JunctionBox.h"

using namespace std;

namespace D8 {

  class Circuits {

    vector<JunctionBox> junctionBoxes_;
    using Circuit = std::vector<size_t>;
    vector<Circuit> circuits_;

    JunctionBox* boxA_ = nullptr;
    JunctionBox* boxB_ = nullptr;

  public:
    Circuits(const vector<JunctionBox> &junctionBoxes) : junctionBoxes_(junctionBoxes) {
      for (int i = 0; i < junctionBoxes_.size(); i++) {
        Circuit circuit;
        circuit.push_back(i);
        circuits_.push_back(circuit);
      }
    }
    vector<Circuit> getCircuits() const { return circuits_; }
    Circuit& getCircuitByJunctionIndex(size_t junctionBoxIndex);
    void mergeNextClosestCircuits();
    long multiplyXOfLastTwoBoxes() {
      return boxA_->getX() * boxB_->getX();
    }
  };

} // namespace D8

#endif // AOC2025_CIRCUITS_H
