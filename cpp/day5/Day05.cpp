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

    std::vector<core::Range> checkedRanges;
    uint64_t totalIngredients{0};
    int idx{0};
    for (auto &range: ranges) {
      idx++;
      // Condense range if required, helps avoid duplicate IDs
      for (const auto &checkedRange: checkedRanges) {
        std::cout << "Checking range: " << range.toString() << " against " << checkedRange.toString() << std::endl;
        range.compressUsingRange(checkedRange);
      }

      // Range can be invalid if it sits inside of an existing range, meaning
      //  the ingredients have alredy been checked and we don't want to add
      //  them again
      if (!range.getInvalid()) {

        // Add one as 10 - 10 = 0, despite there being 1 number shared between the two.
        long long uniqueIngredients = range.getEndId() - range.getStartId() + 1;
        totalIngredients += uniqueIngredients;
        //std::cout << idx << "| " << range.toString() << "\t- Added " << uniqueIngredients
         //         << "\t- Total ingredients: " << totalIngredients << std::endl;
        std::cout << idx << "| " << totalIngredients << std::endl;
        // NOT 364870513812957
        // NOT 364870513812929 too high

        // Check for any overlap (i.e. already tracked fresh ingredient IDs)
        checkedRanges.emplace_back(range);
      }
    }
    return std::to_string(totalIngredients);
  }
} // namespace solutions
