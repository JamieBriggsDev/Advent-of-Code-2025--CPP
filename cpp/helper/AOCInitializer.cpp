//
// Created by Jamie Briggs on 06/12/2023.
//

#include "AOCInitializer.h"

#include <format>
#include <stdexcept>

#include "../day1/Day01.h"
#include "../day10/Day10.h"
#include "../day2/Day02.h"
#include "../day3/Day03.h"
#include "../day4/Day04.h"
#include "../day5/Day05.h"
#include "../day7/Day07.h"
#include "../day8/Day08.h"
#include "../day9/Day09.h"
#include "FileReader.h"

namespace helper {
  solutions::Day *AOCInitializer::getDay(int dayNumber, bool isTest) {
    solutions::Day *day = nullptr;
    switch (dayNumber) {
      case 1:
        day = new solutions::Day01();
        break;
      case 2:
        day = new solutions::Day02();
        break;
      case 3:
        day = new solutions::Day03();
        break;
      case 4:
        day = new solutions::Day04();
        break;
      case 5:
        day = new solutions::Day05();
        break;
      case 7:
        day = new solutions::Day07();
        break;
      case 8:
        day = new solutions::Day08(1000);
        break;
      case 9:
        day = new solutions::Day09();
        break;
      case 10:
        day = new solutions::Day10();
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
