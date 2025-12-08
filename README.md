# Advent of Code 2025

Welcome to my 2025 Advent of Code project!

There are some files which have existed since the beginning of 2025's AoC, and they're taken from previous years. They
are essentially core `helper` libraries which just help speed the process of working on a solution such as opening a
file or code
layout. This helps myself with focusing on working on the solution rather than project quality of life.

## Puzzle inputs!

You will have to include the test inputs yourself as they are not included in the repository:

```shell
mkdir input
cd input
touch day1.txt
```

## Running the code

### CLion

If you would like to run this project locally, it is easiest to open the project in CLion as there are configurations
which should already have been created.

### CMake

However, you can compile and run the project yourself using CMake.

```shell
# Create and open build directory
mkdir build
cd build

# Run CMake from the build directory to generate build files
cmake ..

# Build the application
make
```

Once the application is built, you can run the solutions via arguments passed.

```shell
# In ./build directory created in previous step
./aoc2025 1 # Runs solutions from day 1
./aoc2025 9 # Runs solutions form day 9
```

## Project layout

There are 4 main directories within this project:

- `./cpp`: Contains source code for Advent of Code
- `./sample_input`: Similar to `./input`, but created based on the puzzle instructions or created by myself. They should
  be labelled as `dayX.txt`.
- `./puzzle`: Contains markdown files which have the puzzles copied into them.

## Days

Here are markdown files containing the various puzzles which need completing. They're essentially a copy and paste from
Advent of Code's website, but copying them and formatting to markdown helps me to more time to understand the puzzle
which
needs solving.

| Day                                            | Part One | Part Two |
|------------------------------------------------|----------|----------|
| [Day 1](https://adventofcode.com/2025/day/1)   | ⭐️       | ⭐️       | 
| [Day 2](https://adventofcode.com/2025/day/2)   | ⭐️       | ⭐️       | 
| [Day 3](https://adventofcode.com/2025/day/3)   | ⭐️       | ⭐️       | 
| [Day 4](https://adventofcode.com/2025/day/4)   | ⭐️       | ⭐️       | 
| [Day 5](https://adventofcode.com/2025/day/5)   | ⭐️       |          | 
| [Day 6](https://adventofcode.com/2025/day/6)   |          |          | 
| [Day 7](https://adventofcode.com/2025/day/7)   | ⭐️       |          | 
| [Day 8](https://adventofcode.com/2025/day/8)   |          |          | 
| [Day 9](https://adventofcode.com/2025/day/9)   |          |          | 
| [Day 10](https://adventofcode.com/2025/day/10) |          |          | 
| [Day 11](https://adventofcode.com/2025/day/11) |          |          | 
| [Day12](https://adventofcode.com/2025/day/12)  |          |          | 

