//
// Created by Jamie Briggs on 02/12/2025.
//

#include "InvalidIdFinder.h"

#include <iostream>

#include <ostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

namespace D2 {
  bool InvalidIdFinder::isIdInvalid(long long id) {
    std::string idString = std::to_string(id);

    // Escape if id is odd (Repeat pattern cannot exist
    if (idString.length() % 2 == 1) {
      return false;
    }

    std::string start = idString.substr(0, idString.length() / 2);
    std::string end = idString.substr(idString.length() / 2);

    if (start == end) {
      return true;
    }
    return false;
  }

  bool InvalidIdFinder::isIdInvalidComplex(long long id) {
    std::string idString = std::to_string(id);

    int primeNumbers[] = {2, 3, 5, 7};

    for (int primeNumber: primeNumbers) {

      if (idString.length() % primeNumber != 0) {
        continue;
      }

      vector<std::string> elements;
      const size_t partLength = idString.length() / primeNumber;

      for (size_t i = 0; i < idString.length(); i += partLength) {
        elements.push_back(idString.substr(i, partLength));
      }

      bool allEqual = true;
      for (size_t i = 1; i < elements.size(); i++) {
        if (elements[i] != elements[0]) {
          allEqual = false;
          break;
        }
      }

      if (allEqual) {
        return true;
      }
    }
    return false;
  }
} // namespace D2
