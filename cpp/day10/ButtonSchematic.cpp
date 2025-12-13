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
  std::string ButtonSchematic::toString() const {
    std::stringstream ss;
    for (const auto button: buttons) {
      ss << static_cast<int>(button) << ",";
    }
    return ss.str();
  }
} // namespace D10
