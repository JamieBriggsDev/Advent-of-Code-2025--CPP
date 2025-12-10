//
// Created by Jamie Briggs on 10/12/2025.
//

#ifndef AOC2025_BUTTONSCHEMATIC_H
#define AOC2025_BUTTONSCHEMATIC_H
#include <vector>

namespace D10 {

  class ButtonSchematic {
    std::vector<uint8_t> buttons;
  public:
    ButtonSchematic(const std::string &input);
    ButtonSchematic(const std::vector<uint8_t> &input);
    std::vector<uint8_t> getButtons() const {
      return buttons;
    }

    uint8_t totalButtons() const {
      return buttons.size();
    }
  };

} // namespace D10

#endif // AOC2025_BUTTONSCHEMATIC_H
