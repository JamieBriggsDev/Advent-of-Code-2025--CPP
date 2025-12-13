//
// Created by Jamie Briggs on 10/12/2025.
//

#include "Day10.h"

#include <iostream>
#include <ostream>

#include "LightMachine.h"

namespace solutions {

  std::string Day10::solvePartOne(const helper::SolutionInput *input) {
    std::vector<D10::LightMachine> lightMachines;
    for (const auto &row: input->getTestInput()) {
      D10::LightMachine machine(row);
      lightMachines.emplace_back(row);
    }

    long finalTotal = 0;

    return std::to_string(finalTotal);
  }
  std::string Day10::solvePartTwo(const helper::SolutionInput *input) {
    std::vector<D10::LightMachine> lightMachines;
    for (const auto &row: input->getTestInput()) {
      D10::LightMachine machine(row);
      lightMachines.emplace_back(row);
    }

    long finalTotal = 0;
    std::cout << "Total machines: " << lightMachines.size() << std::endl;
    int idx = 0;
    for (const auto &machine: lightMachines) {
      std::cout << "Machine: " << idx++ << std::endl;
      auto fewestPresses = machine.findFewestJoltagePresses();
      finalTotal += fewestPresses.size();
    }

    return std::to_string(finalTotal);
  }
} // namespace solutions
