//
// Created by Jamie Briggs on 08/12/2025.
//

#include "JunctionBox.h"

#include <cmath>

namespace D8 {
  float JunctionBox::getEuclideanDistance(const JunctionBox& other) {
    float xDiff = x_ - other.x_;
    float yDiff = y_ - other.y_;
    float zDiff = z_ - other.z_;
    return sqrt(pow(xDiff, 2) + pow(yDiff, 2) + pow(zDiff, 2));
  }
} // namespace D8
