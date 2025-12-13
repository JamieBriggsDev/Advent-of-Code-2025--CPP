//
// Created by Jamie Briggs on 13/12/2025.
//

#ifndef AOC2025_MEMORYHELPER_H
#define AOC2025_MEMORYHELPER_H
#include <iostream>
#include <string>

namespace core {

  class MemoryHelper {

  public:
    static void print(const std::string& label) {
      struct rusage usage{};
      getrusage(RUSAGE_SELF, &usage);
      // macOS: ru_maxrss is bytes; Linux: usually kilobytes.
      // If you only care about macOS here (your env), treat it as bytes:
      const double memMiB = usage.ru_maxrss / (1024.0 * 1024.0);
      std::cout << "(" << label << ") Memory used: " << memMiB << " MiB" << std::endl;
    }
  };


}
#endif // AOC2025_MEMORYHELPER_H
