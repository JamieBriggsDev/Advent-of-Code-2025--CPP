//
// Created by Jamie Briggs on 10/12/2025.
//

#include "LightMachine.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>
#include <regex>

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

    this->diagram = new LightDiagram(firstGroup, thirdGroup);
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
    this->diagram->reset();
    int levelsDeep = 1;
    bool found = false;


    std::vector<uint16_t> fewestButtonPressed;
    std::map<std::vector<uint16_t>, std::vector<u_int32_t>> rememberedPatterns;
    while (!found) {
      std::map<std::vector<uint16_t>, std::vector<u_int32_t>> newPatterns;
      std::vector<std::vector<uint16_t>> buttonVariationsToTry;
      std::vector<uint16_t> current;
      current.reserve(1);
      genVariationsNonDecreasing(this->buttonSchematics_.size(), levelsDeep, 0, current, buttonVariationsToTry);

      std::cout << "Trying level " << levelsDeep << " with " << buttonVariationsToTry.size() << " variations"
                << std::endl;
      this->diagram->reset();
      levelsDeep++;
      fewestButtonPressed =
          findFewestJoltagePressesThroughAllVariations(buttonVariationsToTry, rememberedPatterns, newPatterns);
      if (!fewestButtonPressed.empty()) {
        found = true;
      }

      // Swap remembered patterns with new ones as they have been updated
      rememberedPatterns = newPatterns;
    }

    // Sanity check here
    for (const auto &buttonIndex: fewestButtonPressed) {
      ButtonSchematic schematic = this->buttonSchematics_[buttonIndex];
      this->diagram->unpressButtons(schematic);
    }
    for (const auto state: this->diagram->getJoltageState()) {
      if (state != 0) {
        throw core::AocException("Machine is not reset");
      }
    }

    return fewestButtonPressed;
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
  std::vector<uint16_t> LightMachine::findFewestJoltagePressesThroughAllVariations(
      const std::vector<std::vector<uint16_t>> &buttonPressesToTry,
      std::map<std::vector<uint16_t>, std::vector<uint32_t>> previousPatterns,
      std::map<std::vector<uint16_t>, std::vector<uint32_t>> &newPatterns) const {
    std::vector<uint16_t> empty;

    // Loop through current ones so far
    for (const auto &currentVariation: buttonPressesToTry) {

      // Reset at beginning
      this->diagram->reset();

      // Set joltage from previous checks
      if (!previousPatterns.empty()) {
        std::vector<uint16_t> previousCheck = currentVariation;
        previousCheck.pop_back();

        std::vector<uint32_t> previousState = previousPatterns[previousCheck];
        this->diagram->setJoltageState(previousState);
      }

      // Press last button
      uint16_t lastButton = currentVariation.back();
      auto buttonsToPress = this->buttonSchematics_[lastButton];
      this->diagram->pressButtons(buttonsToPress);

      // Is diagram now valid?
      if (this->diagram->isValidJoltage()) {
        // If valid, return the winning variation
        return currentVariation;
      }

      // Cache state of diagram
      newPatterns[currentVariation] = this->diagram->getJoltageState();

      // Reset the diagram if it wasn't found
      this->diagram->reset();
    }

    return empty;
  }
} // namespace D10
