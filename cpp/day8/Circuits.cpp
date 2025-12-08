//
// Created by Jamie Briggs on 08/12/2025.
//

#include "Circuits.h"

#include <math.h>

#include "../core/AocException.h"

using namespace std;

namespace D8 {


  Circuits::Circuit &Circuits::getCircuitByJunctionIndex(size_t junctionBoxIndex) {
    for (auto &circuit: circuits_) {
      for (const auto &junctionBoxIndexInCircuit: circuit) {
        if (junctionBoxIndexInCircuit == junctionBoxIndex) {

          return circuit;
        }
      }
    }

    throw core::AocException("Could not find circuit for junction index");
  }
  void Circuits::mergeNextClosestCircuits() {
    float closestDistance = MAXFLOAT;
    size_t boxAIndex = -1;
    size_t boxBIndex = -1;


    for (int x = 0; x < junctionBoxes_.size() - 1; x++) {
      JunctionBox boxToCheck = junctionBoxes_[x];
      for (int y = x + 1; y < junctionBoxes_.size(); y++) {

        if (boxToCheck.isConnectedToJunctionBox(y)) {
          continue;
        }

        JunctionBox boxToCheckAgainst = junctionBoxes_[y];

        // Check if distance has been calculated before
        float distance = boxToCheck.getEuclideanDistance(boxToCheckAgainst);

        if (distance < closestDistance) {
          closestDistance = distance;
          boxAIndex = x;
          boxBIndex = y;
        }
      }
    }

    if (boxAIndex == static_cast<size_t>(-1) || boxBIndex == static_cast<size_t>(-1)) {
      // No mergeable pair found; you might want to throw or just return
      return;
    }

    // Connect the boxes
    junctionBoxes_[boxAIndex].addConnectedJunctionBox(boxBIndex);
    junctionBoxes_[boxBIndex].addConnectedJunctionBox(boxAIndex);


    Circuit &circuitA = getCircuitByJunctionIndex(boxAIndex);
    Circuit &circuitB = getCircuitByJunctionIndex(boxBIndex);

    // Merge the two circuits if they are different
    if (circuitA != circuitB) {

      for (const auto junctionBoxIndex: circuitB) {
        circuitA.push_back(junctionBoxIndex);
      }
      circuitB.clear();
      // Remove all empty circuits as they can be discarded
      std::erase_if(circuits_, [](const Circuit &c) { return c.empty(); });
    }
    // Remember last connected boxes
    boxA_ = &junctionBoxes_[boxAIndex];
    boxB_ = &junctionBoxes_[boxBIndex];
  }
} // namespace D8
