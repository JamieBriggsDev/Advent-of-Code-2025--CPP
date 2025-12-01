//
// Created by Jamie Briggs on 06/12/2023.
//

#include "AOCInitializer.h"

#include <format>
#include <stdexcept>

#include "../day1/Day01.h"
#include "FileReader.h"

namespace helper {
  solutions::Day *AOCInitializer::getDay(int dayNumber, bool isTest) {
    solutions::Day *day = nullptr;
    switch (dayNumber) {
      case 1:
        day = new solutions::Day01();
        break;
      default:
        printf("Unknown day passed %d", dayNumber);
        throw std::invalid_argument("Day could not be found");
    }
    day->setTestMode(isTest);
    return day;
  }

  SolutionInput *AOCInitializer::getInput(const string &filePath) {
    return FileReader::readFile(filePath);
  }

  SolutionInput *AOCInitializer::getInput(int dayNumber) {
    auto file_location = std::format("../input/day{}.txt", dayNumber);
    return getInput(file_location);
  }

} // namespace helper
