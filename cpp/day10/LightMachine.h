//
// Created by Jamie Briggs on 10/12/2025.
//

#ifndef AOC2025_LIGHTMACHINE_H
#define AOC2025_LIGHTMACHINE_H
#include <map>
#include <unordered_map>
#include "LightDiagram.h"

namespace D10 {

  struct VecU16Hash {
    size_t operator()(const std::vector<uint16_t> &v) const noexcept {
      // Cheap-ish hash combiner good enough for small integer vectors.
      size_t h = 1469598103934665603ull;
      for (uint16_t x: v) {
        h ^= static_cast<size_t>(x) + 0x9e3779b97f4a7c15ull + (h << 6) + (h >> 2);
      }
      return h;
    }
  };

  class LightMachine {
    std::unique_ptr<LightDiagram> diagram;
    std::vector<ButtonSchematic> buttonSchematics_;

    bool recursiveFindFewestPresses(std::vector<uint16_t> &buttonsPressed, uint16_t currentLevel,
                                    uint16_t maximumLevel) const;
    std::vector<uint16_t> findFewestJoltagePressesThroughAllVariations(
        const std::vector<std::vector<uint16_t>> &buttonPressesToTry,
        const std::unordered_map<std::vector<uint16_t>, std::vector<uint32_t>, VecU16Hash> &previousPatterns,
        std::unordered_map<std::vector<uint16_t>, std::vector<uint32_t>, VecU16Hash> &newPatterns) const;

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
