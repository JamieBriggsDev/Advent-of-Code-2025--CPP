//
// Created by Jamie Briggs on 10/12/2025.
//

#ifndef AOC2025_LIGHTMACHINE_H
#define AOC2025_LIGHTMACHINE_H
#include "LightDiagram.h"
#include <map>

namespace D10 {

  class LightMachine {
    LightDiagram *diagram;
    std::vector<ButtonSchematic> buttonSchematics_;

    bool recursiveFindFewestPresses(std::vector<uint16_t> &buttonsPressed, uint16_t currentLevel,
                                    uint16_t maximumLevel) const;
    std::vector<uint16_t> findFewestJoltagePressesThroughAllVariations(const std::vector<std::vector<uint16_t>>& buttonPressesToTry,
      std::map<std::vector<uint16_t>,  std::vector<uint32_t>> previousPatterns,
      std::map<std::vector<uint16_t>,  std::vector<uint32_t>> &newPatterns) const;
  public:
    LightMachine(const std::string &input);
    LightDiagram getDiagram() const { return *diagram; }
    std::vector<ButtonSchematic> getButtonSchematics() const { return buttonSchematics_; }
    std::vector<uint16_t> findFewestPresses() const;
    std::vector<uint16_t> findFewestJoltagePresses() const;
    void printButtons(std::vector<uint16_t> buttonsPressed) const;
  };

} // namespace D10

#endif // AOC2025_LIGHTMACHINE_H
