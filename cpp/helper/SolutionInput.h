//
// Created by Jamie Briggs on 05/12/2023.
//

#ifndef TESTINPUT_H
#define TESTINPUT_H
#include <string>
#include <utility>
#include <vector>

using namespace std;

namespace helper {

  class SolutionInput {
    const vector<string> testInput;

  public:
    explicit SolutionInput(vector<string> input) : testInput(std::move(input)) {}

    [[nodiscard]] vector<string> getTestInput() const;
    [[nodiscard]] vector<vector<string>> getSplitTestInput(std::string rowToSplitBy) const;
    [[nodiscard]] int getTotalRowsInInput() const { return testInput.size(); };
  };

} // namespace helper


#endif // TESTINPUT_H
