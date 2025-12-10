//
// Created by Jamie Briggs on 10/12/2025.
//

#include "LightMachine.h"

#include <algorithm>
#include <ranges>
#include <regex>

#include "../core/AocException.h"

namespace D10 {


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

    this->diagram = new LightDiagram(firstGroup, thirdGroup);
    for (const auto &buttonPattern: secondGroup) {
      this->buttonSchematics_.emplace_back(buttonPattern);
    }

    // Sort the button schematics so the first ones have less buttons
    std::ranges::sort(this->buttonSchematics_, [](const ButtonSchematic &a, const ButtonSchematic &b) {
      return a.totalButtons() < b.totalButtons();
    });

    // TODO: Joltages
  }
  std::vector<uint16_t> LightMachine::findFewestPresses() const {
    std::vector<uint16_t> buttonsPressed;
    this->diagram->reset();
    int levelsDeep = 0;
    bool found = false;
    while (!found) {
      this->diagram->reset();
      levelsDeep++;
      if (recursiveFindFewestPresses(buttonsPressed, 0, levelsDeep)) {
        found = true;
      }
    }

    // Sanity check here
    for (const auto &buttonIndex: buttonsPressed) {
      ButtonSchematic schematic = this->buttonSchematics_[buttonIndex];
      this->diagram->pressButtons(schematic);
    }
    for (const auto state: this->diagram->getState()) {
      if (state) {
        throw core::AocException("Machine is not reset");
      }
    }

    return buttonsPressed;
  }
  std::vector<uint16_t> LightMachine::findFewestJoltagePresses() const {
    std::vector<uint16_t> buttonsPressed;
    this->diagram->reset();
    int levelsDeep = 0;
    bool found = false;
    while (!found) {
      this->diagram->reset();
      levelsDeep++;
      if (recursiveFindFewestJoltagePresses(buttonsPressed, 0, levelsDeep)) {
        found = true;
      }
    }

    // Sanity check here
    for (const auto &buttonIndex: buttonsPressed) {
      ButtonSchematic schematic = this->buttonSchematics_[buttonIndex];
      this->diagram->unpressButtons(schematic);
    }
    for (const auto state: this->diagram->getJoltageState()) {
      if (state != 0) {
        throw core::AocException("Machine is not reset");
      }
    }

    return buttonsPressed;

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
      this->diagram->pressButtons(buttonToPressThisIteration);
      buttonsPressed.push_back(i);

      if (this->diagram->isValid() || recursiveFindFewestPresses(buttonsPressed, currentLevel + 1, maximumLevel)) {
        return true;
      }

      // Press same buttons again to "undo"
      // Remove last button pressed
      this->diagram->pressButtons(buttonToPressThisIteration);
      buttonsPressed.pop_back();
    }

    return false;
  }
  bool LightMachine::recursiveFindFewestJoltagePresses(std::vector<uint16_t> &buttonsPressed, uint16_t currentLevel,
                                                       uint16_t maximumLevel) const {
    if (currentLevel >= maximumLevel) {
      return false;
    }
    for (int i = 0; i < this->buttonSchematics_.size(); i++) {

      auto buttonToPressThisIteration = this->buttonSchematics_[i];
      // Press button
      // Add button reference to buttons pressed
      this->diagram->pressButtons(buttonToPressThisIteration);
      buttonsPressed.push_back(i);

      if (this->diagram->isValidJoltage() || recursiveFindFewestJoltagePresses(buttonsPressed, currentLevel + 1, maximumLevel)) {
        return true;
      }

      // Press same buttons again to "undo"
      // Remove last button pressed
      this->diagram->unpressButtons(buttonToPressThisIteration);
      buttonsPressed.pop_back();

    }

    return false;
  }
} // namespace D10
