//
// Created by Jamie Briggs on 01/12/2024.
//

#include "Day01.h"


#include <iostream>
#include <vector>

#include "../helper/SolutionInput.h"

#include <regex>

#include "Dial.h"

using namespace std;

namespace solutions {
  string Day01::solvePartOne(const helper::SolutionInput *input) {
    auto dial = make_unique<Day1::Dial>(50);
    moveDial(input, dial);
    return to_string(dial->getTotalTimesDialEndsOnZero());
  }

  string Day01::solvePartTwo(const helper::SolutionInput *input) {
    auto dial = make_unique<Day1::Dial>(50);
    moveDial(input, dial);
    return to_string(dial->getTotalTimesDialTouchesZero());
  }

  void Day01::moveDial(const helper::SolutionInput *input, unique_ptr<Day1::Dial> &dial) {
    const regex listsRegex("([RL])([0-9]+)");
    auto dialValues = std::vector<int16_t>();

    for (const auto &row: input->getTestInput()) {
      smatch m;
      regex_search(row, m, listsRegex);

      const char a = m[1].str()[0];
      int b = std::stoi(m[2]);

      // If left, make b negative
      if (a == 'L')
        b *= -1;

      dialValues.push_back(b);
    }

    for (const auto &value: dialValues) {
      dial->moveDial(value);
    }
  }

} // namespace solutions
