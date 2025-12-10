//
// Created by Jamie Briggs on 10/12/2025.
//

#include "ButtonSchematic.h"
#include <sstream>

namespace D10 {


  ButtonSchematic::ButtonSchematic(const std::string &input) {
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ',')) {
      buttons.push_back(std::stoi(token));
    }
  }
  ButtonSchematic::ButtonSchematic(const std::vector<uint8_t> &input) {
    buttons = input;
  }
} // namespace D10
