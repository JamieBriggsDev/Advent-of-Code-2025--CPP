//
// Created by Jamie Briggs on 06/12/2023.
//

#ifndef AOCINITIALIZER_H
#define AOCINITIALIZER_H
#include "SolutionInput.h"

namespace solutions {
  class Day;
}

namespace helper {

class AOCInitializer {
public:
  static solutions::Day* getDay(int dayNumber, bool test);
  static SolutionInput* getInput(const string &filePath);
  static SolutionInput* getInput(int dayNumber);
};

} // helper

#endif //AOCINITIALIZER_H
