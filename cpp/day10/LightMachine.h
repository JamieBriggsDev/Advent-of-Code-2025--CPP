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
    LightMachine(std::string &input);
    LightDiagram getDiagram() const {
      return *diagram;
    }
    std::vector<ButtonSchematic> getButtonSchematics() const {
      return buttonSchematics_;
    }
  };

} // namespace D10

#endif // AOC2025_LIGHTMACHINE_H
