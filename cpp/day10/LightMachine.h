//
// Created by Jamie Briggs on 10/12/2025.
//

#ifndef AOC2025_LIGHTMACHINE_H
#define AOC2025_LIGHTMACHINE_H
#include "LightDiagram.h"

namespace D10 {

  class LightMachine {
    LightDiagram* diagram;
    std::vector<ButtonSchematic> buttonSchematics_;
    public:
    bool recursiveFindFewestPresses(std::vector<uint8_t>& buttonsPressed, uint8_t currentLevel, uint8_t maximumLevel) const;
    LightMachine(std::string &input);
    LightDiagram getDiagram() const {
      return *diagram;
    }
    std::vector<ButtonSchematic> getButtonSchematics() const {
      return buttonSchematics_;
    }
    std::vector<uint8_t> findFewestPresses() const;
  };

} // namespace D10

#endif // AOC2025_LIGHTMACHINE_H
