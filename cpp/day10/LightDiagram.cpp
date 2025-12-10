//
// Created by Jamie Briggs on 10/12/2025.
//

#include "LightDiagram.h"

#include <sstream>

namespace D10 {


  LightDiagram::LightDiagram(std::string &input) {
    int length = input.length();
    for (int i = 0; i < length; i++) {
      state.push_back(false);
      goal.push_back(input[i] == '#');
      // These would probably never be used, but initialize for safety
      joltageState.push_back(0);
      joltageGoal.push_back(0);
    }
  }
  LightDiagram::LightDiagram(std::string &input, std::string &joltageInput) {
    int length = input.length();
    for (int i = 0; i < length; i++) {
      state.push_back(false);
      goal.push_back(input[i] == '#');
    }

    std::stringstream ss(joltageInput);
    std::string token;
    while (std::getline(ss, token, ',')) {
      joltageState.push_back(0);
      joltageGoal.push_back(std::stoi(token));
    }
  }
  void LightDiagram::pressButtons(const ButtonSchematic &buttonSchematic) {
    for (const auto &button: buttonSchematic.getButtons()) {
      state[button] = !state[button];
      joltageState[button]++;
    }
  }
  void LightDiagram::unpressButtons(const ButtonSchematic &buttonSchematic) {
    for (const auto &button: buttonSchematic.getButtons()) {
      state[button] = !state[button];
      joltageState[button]--;
    }
  }
  void LightDiagram::reset() {
    for (auto && i : state) {
      i = false;
    }
    for (auto && i : joltageState) {
      i = 0;
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
  bool LightDiagram::isValidJoltage() const {
    bool valid = true;
    for (int i = 0; i < joltageState.size(); i++) {
      if (valid && joltageState[i] != joltageGoal[i]) {
        valid = false;
      }
    }
    return valid;
  }
} // namespace D10
