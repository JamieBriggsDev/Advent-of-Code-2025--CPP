#include <iostream>
#include <chrono>

#include "cpp/Day.h"
#include "cpp/helper/AOCInitializer.h"

using namespace helper;
using namespace solutions;


int main(int argc, char* argv[]) {
  // Get the start time for loading input
  const auto startInput = std::chrono::high_resolution_clock::now();
  const auto day = AOCInitializer::getDay(std::stoi(argv[1]), argc > 2);
  const auto input = AOCInitializer::getInput(std::stoi(argv[1]));
  const auto endInput = std::chrono::high_resolution_clock::now();

  // List time elapsed to load data
  const auto inputDuration =
      std::chrono::duration_cast<std::chrono::milliseconds>(endInput - startInput);
  std::cout << "\nTook " << inputDuration.count() << "ms to load data\n\n";

  // Solve part one of solution
  std::cout << "Solving Part 1 of solution...";
  const auto startPartOne = std::chrono::high_resolution_clock::now();
  const auto solve_part_one = day->solvePartOne(input);
  const auto endPartOne = std::chrono::high_resolution_clock::now();
  const auto partOneDuration =
      std::chrono::duration_cast<std::chrono::milliseconds>(endPartOne - startPartOne);
  std::cout << "\nPart 1 solution: " << solve_part_one;
  std::cout << "\nPart 1 took " << partOneDuration.count() << "ms to solve";

  std::cout << std::endl;

  // Solve part two of solution
  std::cout << "\nSolving Part 2 of solution...";
  const auto startPartTwo = std::chrono::high_resolution_clock::now();
  const auto solve_part_two = day->solvePartTwo(input);
  const auto endPartTwo = std::chrono::high_resolution_clock::now();
  const auto partTwoDuration =
      std::chrono::duration_cast<std::chrono::milliseconds>(endPartTwo - startPartTwo);
  std::cout << "\nPart 2 solution: " << solve_part_two;
  std::cout << "\nPart 2 took " << partTwoDuration.count() << "ms to solve\n";

  return 0;
}


