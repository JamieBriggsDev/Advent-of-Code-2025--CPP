//
// Created by Jamie Briggs on 10/12/2025.
//

#include "LightDiagram.h"

namespace D10 {


  LightDiagram::LightDiagram(std::string &input) {
    int length = input.length();
    for (int i = 0; i < length; i++) {
      state.push_back(false);
      goal.push_back(input[i] == '#');
    }
  }
  void LightDiagram::pressButtons(const ButtonSchematic &buttonSchematic) {
    for (const auto &button: buttonSchematic.getButtons()) {
      state[button] = !state[button];
    }
  }
  void LightDiagram::reset() {
    for (int i = 0; i < state.size(); i++) {
      state[i] = false;
    }
  }
  bool LightDiagram::isValid() {
    bool valid = true;
    for (int i = 0; i < state.size(); i++) {
      if (valid && state[i] != goal[i]) {
        valid = false;
      }
    }
    return valid;
  }
} // namespace D10
