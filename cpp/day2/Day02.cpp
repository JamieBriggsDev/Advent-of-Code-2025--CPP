//
// Created by Jamie Briggs on 02/12/2025.
//

#include "Day02.h"

#include <iostream>
#include <ostream>

#include "../helper/SolutionInput.h"

#include <regex>
#include <sstream>

#include "InvalidIdFinder.h"
#include "Range.h"


using namespace std;

namespace solutions {
  string Day02::solvePartOne(const SolutionInput *input) {
    const auto rowInput = input->getTestInput()[0];

    // Split row by comma
    std::stringstream ss(rowInput);
    std::string segment;
    std::vector<std::string> values;

    while(std::getline(ss, segment, ','))
    {
      values.push_back(segment);
    }


    const regex listsRegex("([0-9]+)-([0-9]+)");
    vector<D2::Range> ranges;
    // Get all ranges
    for (const auto &row: values) {
      smatch m;
      regex_search(row, m, listsRegex);

      const long start = std::stol(m[1]);
      const long end = std::stol(m[2]);
      D2::Range range(start, end);
      ranges.push_back(range);
    }

    long long result = 0;
    // Loop through each range
    for (const auto &range: ranges) {
      const auto availableIds = range.getFullRange();
      for (const auto &id: availableIds) {
        if (D2::InvalidIdFinder::isIdInvalid(id)) {
          result += id;
        }
      }
    }

    return to_string(result);
  }

  string Day02::solvePartTwo(const SolutionInput *input) {

    const auto rowInput = input->getTestInput()[0];

    // Split row by comma
    std::stringstream ss(rowInput);
    std::string segment;
    std::vector<std::string> values;

    while(std::getline(ss, segment, ','))
    {
      values.push_back(segment);
    }


    const regex listsRegex("([0-9]+)-([0-9]+)");
    vector<D2::Range> ranges;
    // Get all ranges
    for (const auto &row: values) {
      smatch m;
      regex_search(row, m, listsRegex);

      const long start = std::stol(m[1]);
      const long end = std::stol(m[2]);
      D2::Range range(start, end);
      ranges.push_back(range);
    }

    long long result = 0;
    // Loop through each range
    for (const auto &range: ranges) {
      const auto availableIds = range.getFullRange();
      for (const auto &id: availableIds) {
        if (D2::InvalidIdFinder::isIdInvalidComplex(id)) {
          result += id;
        }
      }
    }

    return to_string(result);
  }

} // namespace solutions
