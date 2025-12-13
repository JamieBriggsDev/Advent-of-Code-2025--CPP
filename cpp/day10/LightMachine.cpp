//
// Created by Jamie Briggs on 10/12/2025.
//

#include "LightMachine.h"

#include <algorithm>
#include <iostream>
#include <ranges>
#include <regex>
#include <unordered_map>

#include "../core/AocException.h"

namespace D10 {

  void genVariationsNonDecreasing(int numButtons, int presses, int minButton, std::vector<uint16_t> &current,
                                  std::vector<std::vector<uint16_t>> &out) {
    if ((int) current.size() == presses) {
      out.push_back(current);
      return;
    }

    for (int b = minButton; b < numButtons; ++b) {
      current.push_back(b);
      genVariationsNonDecreasing(numButtons, presses, b, current, out); // b again allowed
      current.pop_back();
    }
  }

  // Backtracking search that enumerates the same non-decreasing variations,
  // but avoids building/storing them and avoids resetting/replaying each one.
  static bool tryJoltageAtDepthNonDecreasing(
      LightDiagram &diagram,
      const std::vector<ButtonSchematic> &buttons,
      int remainingPresses,
      uint16_t minButtonIndex,
      std::vector<uint16_t> &current) {

    if (remainingPresses == 0) {
      return diagram.isValidJoltage();
    }

    for (uint16_t b = minButtonIndex; b < buttons.size(); ++b) {
      diagram.pressButtons(buttons[b]);
      current.push_back(b);

      if (tryJoltageAtDepthNonDecreasing(diagram, buttons, remainingPresses - 1, b, current)) {
        return true;
      }

      diagram.unpressButtons(buttons[b]); // undo this branch
      current.pop_back();
    }

    return false;
  }

  std::vector<uint16_t> LightMachine::findFewestJoltagePresses() const {
    this->lightDiagram_->reset();

    int levelsDeep = 1;
    for (;;) {
      std::vector<uint16_t> current;
      current.reserve(levelsDeep);

      this->lightDiagram_->reset();

      std::cout << "Trying level " << levelsDeep << std::endl;

      if (tryJoltageAtDepthNonDecreasing(*this->lightDiagram_, this->buttonSchematics_,
                                            levelsDeep, 0, current)) {
        // Sanity check here
        for (const auto &buttonIndex: current) {
          ButtonSchematic schematic = this->buttonSchematics_[buttonIndex];
          this->lightDiagram_->unpressButtons(schematic);
        }
        for (const auto state: this->lightDiagram_->getJoltageState()) {
          if (state != 0) {
            throw core::AocException("Machine is not reset");
          }
        }

        return current;
      }

      ++levelsDeep;
    }
  }

  std::vector<std::vector<uint16_t>> allButtonVariations(int numButtons, int presses) {
    std::vector<std::vector<uint16_t>> out;
    std::vector<uint16_t> current;
    current.reserve(presses);

    genVariationsNonDecreasing(numButtons, presses, 0, current, out);
    return out;
  }

  LightMachine::LightMachine(const std::string &input) {
    // Three capture groups
    // [   ]   |   ( ) ( ) ( )   |   {  }
    const std::regex machineRegex(R"(\[(.*?)\]|\((\d+(?:,\d+)*)\)|\{(\d+(?:,\d+)*)\})");

    std::string firstGroup;
    std::vector<std::string> secondGroup;
    std::string thirdGroup;

    for (std::sregex_iterator it(input.begin(), input.end(), machineRegex); it != std::sregex_iterator(); ++it) {
      const std::smatch &match = *it;
      if (match[1].matched) {
        firstGroup = match[1];
      } else if (match[2].matched) {
        secondGroup.push_back(match[2].str());
      } else if (match[3].matched) {
        thirdGroup = match[3];
      }
    }

    this->lightDiagram_ = std::make_unique<LightDiagram>(firstGroup, thirdGroup);
    for (const auto &buttonPattern: secondGroup) {
      this->buttonSchematics_.emplace_back(buttonPattern);
    }

    // Sort the button schematics so the first ones have less buttons
    std::ranges::sort(this->buttonSchematics_, [](const ButtonSchematic &a, const ButtonSchematic &b) {
      return a.totalButtons() < b.totalButtons();
    });
  }
  std::vector<uint16_t> LightMachine::findFewestPresses() const {
    std::vector<uint16_t> buttonsPressed;
    this->lightDiagram_->reset();
    int levelsDeep = 0;
    bool found = false;
    while (!found) {
      this->lightDiagram_->reset();
      levelsDeep++;
      if (recursiveFindFewestPresses(buttonsPressed, 0, levelsDeep)) {
        found = true;
      }
    }

    // Sanity check here
    for (const auto &buttonIndex: buttonsPressed) {
      ButtonSchematic schematic = this->buttonSchematics_[buttonIndex];
      this->lightDiagram_->pressButtons(schematic);
    }
    for (const auto state: this->lightDiagram_->getState()) {
      if (state) {
        throw core::AocException("Machine is not reset");
      }
    }

    return buttonsPressed;
  }
  void LightMachine::printButtons(std::vector<uint16_t> buttonsPressed) const {
    for (const auto &buttonIdx: buttonsPressed) {
      auto button = this->buttonSchematics_[buttonIdx];
      std::cout << button.toString() << " | ";
    }
    std::cout << std::endl;
  }


  bool LightMachine::recursiveFindFewestPresses(std::vector<uint16_t> &buttonsPressed, uint16_t currentLevel,
                                                uint16_t maximumLevel) const {
    if (currentLevel >= maximumLevel) {
      return false;
    }
    for (int i = 0; i < this->buttonSchematics_.size(); i++) {

      auto buttonToPressThisIteration = this->buttonSchematics_[i];
      // Press button
      // Add button reference to buttons pressed
      this->lightDiagram_->pressButtons(buttonToPressThisIteration);
      buttonsPressed.push_back(i);

      if (this->lightDiagram_->isValid() || recursiveFindFewestPresses(buttonsPressed, currentLevel + 1, maximumLevel)) {
        return true;
      }

      // Press same buttons again to "undo"
      // Remove last button pressed
      this->lightDiagram_->pressButtons(buttonToPressThisIteration);
      buttonsPressed.pop_back();
    }

    return false;
  }
  std::vector<uint16_t> LightMachine::findFewestJoltagePressesThroughAllVariations(
      const std::vector<std::vector<uint16_t>> &buttonPressesToTry) const {
    std::vector<uint16_t> empty;

    // Loop through current ones so far
    for (const auto &currentVariation: buttonPressesToTry) {

      // Reset at beginning
      this->lightDiagram_->reset();


      // Press all buttons
      for (const auto &buttonIdx: currentVariation) {
        this->lightDiagram_->pressButtons(this->buttonSchematics_[buttonIdx]);
      }

      // Is diagram now valid?
      if (this->lightDiagram_->isValidJoltage()) {
        // If valid, return the winning variation
        return currentVariation;
      }

    }

    return empty;
  }
} // namespace D10
