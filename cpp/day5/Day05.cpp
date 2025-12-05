//
// Created by Jamie Briggs on 05/12/2025.
//

#include "Day05.h"

#include <iostream>
#include <regex>
#include <unordered_set>
#include "../core/Range.h"

namespace solutions {


  std::string Day05::solvePartOne(const helper::SolutionInput *input) {
    auto splitResult = input->getSplitTestInput("");
    // Create ranges
    const regex listsRegex("([0-9]+)-([0-9]+)");
    vector<core::Range> ranges;
    // Get all ranges
    for (const auto &row: splitResult[0]) {
      smatch m;
      regex_search(row, m, listsRegex);

      const long start = std::stol(m[1]);
      const long end = std::stol(m[2]);
      core::Range range(start, end);
      ranges.push_back(range);
    }

    // Check if second part of input fits in any range and add up total
    std::unordered_set<long> uniqueIngredients;

    for (const auto ingredientId: splitResult[1]) {
      for (const auto &range: ranges) {
        long id = std::stol(ingredientId);
        if (range.isInRange(id)) {
          uniqueIngredients.insert(id);
          break;
        }
      }
    }
    return std::to_string(uniqueIngredients.size());
  }


  std::string Day05::solvePartTwo(const helper::SolutionInput *input) {
    auto splitResult = input->getSplitTestInput("");
    // Create ranges
    const regex listsRegex("([0-9]+)-([0-9]+)");
    vector<core::Range> ranges;
    // Get all ranges
    for (const auto &row: splitResult[0]) {
      smatch m;
      regex_search(row, m, listsRegex);

      const long start = std::stol(m[1]);
      const long end = std::stol(m[2]);
      core::Range range(start, end);
      ranges.push_back(range);
    }

    // Check if second part of input fits in any range and add up total
    std::unordered_set<long> uniqueFreshIngredientIds;

    // TODO: Handle overlapping ingredients :(
    long totalIngredients = 0;
    for (const auto &range: ranges) {
      long uniqueIngredients = range.getEndId() - range.getStartId() + 1;
      totalIngredients += uniqueIngredients;
    }
    return std::to_string(totalIngredients);
  }
} // namespace solutions
