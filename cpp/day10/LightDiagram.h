//
// Created by Jamie Briggs on 10/12/2025.
//

#ifndef AOC2025_LIGHTDIAGRAM_H
#define AOC2025_LIGHTDIAGRAM_H
#include <vector>

#include "ButtonSchematic.h"

namespace D10 {

  class LightDiagram {
    std::vector<bool> state;
    std::vector<bool> goal;
    std::vector<u_int8_t> joltageState;
    std::vector<u_int8_t> joltageGoal;
  public:
    LightDiagram(std::string &input);
    LightDiagram(std::string &input, std::string &joltageInput);
    void pressButtons(const ButtonSchematic & buttonSchematic);
    void unpressButtons(const ButtonSchematic & buttonSchematic);
    std::vector<bool> getState() const {
      return state;
    }
    std::vector<bool> getGoal() const {
      return goal;
    }
    std::vector<u_int8_t> getJoltageState() const {
      return joltageState;
    }
    std::vector<u_int8_t> getJoltageGoal() const {
      return joltageGoal;
    }
    void reset();
    bool isValid();
    bool isValidJoltage() const;
  };

} // namespace D10

#endif // AOC2025_LIGHTDIAGRAM_H
