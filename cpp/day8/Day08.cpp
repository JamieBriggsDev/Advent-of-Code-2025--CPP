//
// Created by Jamie Briggs on 08/12/2025.
//

#include "Day08.h"
#include <algorithm>
#include <iostream>

#include "Circuits.h"
#include "JunctionBox.h"

namespace solutions {


  std::string Day08::solvePartOne(const helper::SolutionInput *input) {

    std::vector<D8::JunctionBox> junctionBoxes;
    for (const auto &row: input->getTestInput()) {
      junctionBoxes.emplace_back(row);
    }
    circuits_p = new D8::Circuits(junctionBoxes);
    for (int i = 0; i < this->totalConnections; i++) {
      std::cout << "Merging circuits... step " << i << std::endl;
      circuits_p->mergeNextClosestCircuits();
    }

    std::vector<int> sizes;
    for (const auto &circuit: circuits_p->getCircuits()) {
      sizes.emplace_back(circuit.size());
    }

    std::sort(sizes.begin(), sizes.end(), std::greater<>());

    int result = sizes[0] * sizes[1] * sizes[2];
    return std::to_string(result);
  }

  std::string Day08::solvePartTwo(const helper::SolutionInput *input) {
    std::cout << "\n\nContinuing off from previous part from step " << this->totalConnections << std::endl;
    int step = this->totalConnections;
    while (circuits_p->getCircuits().size() > 1) {
      std::cout << "Merging circuits... step " << step++ << "\tTotal circuits: " << circuits_p->getCircuits().size()
                << std::endl;
      circuits_p->mergeNextClosestCircuits();
    }

    int result = circuits_p->multiplyXOfLastTwoBoxes();
    return std::to_string(result);
  }
} // namespace solutions
