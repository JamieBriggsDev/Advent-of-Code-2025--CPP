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
  public:
    LightDiagram(std::string &input);
    void pressButtons(const ButtonSchematic & buttonSchematic);
    std::vector<bool> getState() const {
      return state;
    }
    std::vector<bool> getGoal() const {
      return goal;
    }
    bool isValid();
  };

} // namespace D10

#endif // AOC2025_LIGHTDIAGRAM_H
