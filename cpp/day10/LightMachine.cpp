//
// Created by Jamie Briggs on 10/12/2025.
//

#include "LightMachine.h"

#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <limits>

#include "../core/AocException.h"

namespace D10 {


  LightMachine::LightMachine(const std::string &input) {
    // Three capture groups
    // [   ]   |   ( ) ( ) ( )   |   {  }
    const std::regex machineRegex(R"(\[(.*?)\]|\((\d+(?:,\d+)*)\)|\{(\d+(?:,\d+)*)\})");

    std::string firstGroup;
    std::vector<std::string> secondGroup;
    std::string thirdGroup;

    for (std::sregex_iterator it(input.begin(), input.end(), machineRegex); it != std::sregex_iterator(); ++it) {
      const std::smatch &match = *it;
      if (match[1].matched) {
        firstGroup = match[1];
      } else if (match[2].matched) {
        secondGroup.push_back(match[2].str());
      } else if (match[3].matched) {
        thirdGroup = match[3];
      }
    }

    this->lightDiagram_ = std::make_unique<LightDiagram>(firstGroup, thirdGroup);
    for (const auto &buttonPattern: secondGroup) {
      this->buttonSchematics_.emplace_back(buttonPattern);
    }

    // Sort the button schematics so the first ones have less buttons
    std::ranges::sort(this->buttonSchematics_, [](const ButtonSchematic &a, const ButtonSchematic &b) {
      return a.totalButtons() < b.totalButtons();
    });
  }
  std::vector<uint16_t> LightMachine::findFewestPresses() const {
    std::vector<uint16_t> buttonsPressed;
    this->lightDiagram_->reset();
    int levelsDeep = 0;
    bool found = false;
    while (!found) {
      this->lightDiagram_->reset();
      levelsDeep++;
      if (recursiveFindFewestPresses(buttonsPressed, 0, levelsDeep)) {
        found = true;
      }
    }

    // Sanity check here
    for (const auto &buttonIndex: buttonsPressed) {
      ButtonSchematic schematic = this->buttonSchematics_[buttonIndex];
      this->lightDiagram_->pressButtons(schematic);
    }
    for (const auto state: this->lightDiagram_->getState()) {
      if (state) {
        throw core::AocException("Machine is not reset");
      }
    }

    return buttonsPressed;
  }
  void LightMachine::printButtons(std::vector<uint16_t> buttonsPressed) const {
    for (const auto &buttonIdx: buttonsPressed) {
      auto button = this->buttonSchematics_[buttonIdx];
      std::cout << button.toString() << " | ";
    }
    std::cout << std::endl;
  }
  bool LightMachine::recursiveFindFewestPresses(std::vector<uint16_t> &buttonsPressed, uint16_t currentLevel,
                                                uint16_t maximumLevel) const {
    if (currentLevel >= maximumLevel) {
      return false;
    }
    for (int i = 0; i < this->buttonSchematics_.size(); i++) {

      auto buttonToPressThisIteration = this->buttonSchematics_[i];
      // Press button
      // Add button reference to buttons pressed
      this->lightDiagram_->pressButtons(buttonToPressThisIteration);
      buttonsPressed.push_back(i);

      if (this->lightDiagram_->isValid() ||
          recursiveFindFewestPresses(buttonsPressed, currentLevel + 1, maximumLevel)) {
        return true;
      }

      // Press same buttons again to "undo"
      // Remove last button pressed
      this->lightDiagram_->pressButtons(buttonToPressThisIteration);
      buttonsPressed.pop_back();
    }

    return false;
  }

  // BFS implementation
  struct Prev {
    uint64_t prevKey;
    uint16_t buttonIdx;
  };

  static std::vector<std::vector<uint64_t>> computeJoltageDeltas(
      LightDiagram &diagram,
      const std::vector<ButtonSchematic> &buttons) {

    diagram.reset();
    const auto goal = diagram.getJoltageGoal();
    const int n = (int) goal.size();

    std::vector<std::vector<uint64_t>> deltas;
    deltas.reserve(buttons.size());

    for (const auto &btn : buttons) {
      diagram.reset();
      const auto before = diagram.getJoltageState();

      diagram.pressButtons(btn);

      const auto after = diagram.getJoltageState();

      if ((int) before.size() != n || (int) after.size() != n) {
        throw core::AocException("Joltage state size mismatch");
      }

      std::vector<uint64_t> d(n, 0);
      for (int i = 0; i < n; ++i) {
        if (after[i] < before[i]) {
          throw core::AocException("Button decreases joltage (monotone BFS assumption violated)");
        }
        d[i] = after[i] - before[i];
      }
      deltas.push_back(std::move(d));
    }

    diagram.reset();
    return deltas;
  }

  static std::vector<uint16_t> reconstruct(uint64_t goalKey,
                                           uint64_t startKey,
                                           const std::unordered_map<uint64_t, Prev> &parent) {
    std::vector<uint16_t> presses;
    for (uint64_t k = goalKey; k != startKey; ) {
      auto it = parent.find(k);
      if (it == parent.end()) break; // should not happen
      presses.push_back(it->second.buttonIdx);
      k = it->second.prevKey;
    }
    std::reverse(presses.begin(), presses.end());
    return presses;
  }

  std::vector<uint16_t> LightMachine::findFewestJoltagePresses() const {
    this->lightDiagram_->reset();

    const std::vector<uint64_t> goal = this->lightDiagram_->getJoltageGoal();
    const int n = static_cast<int>(goal.size());

    auto deltas = computeJoltageDeltas(*this->lightDiagram_, this->buttonSchematics_);
    const int m = static_cast<int>(deltas.size());

    // Build 64-bit mixed-radix multipliers
    std::vector<uint64_t> mul(n, 1);
    for (int i = 1; i < n; ++i) {
      const uint64_t base = goal[i - 1] + 1ULL;
      if (mul[i - 1] > std::numeric_limits<uint64_t>::max() / base) {
        throw core::AocException("State encoding overflow (goal too large)");
      }
      mul[i] = mul[i - 1] * base;
    }

    auto encode = [&](const std::vector<uint64_t> &s) -> uint64_t {
      uint64_t k = 0;
      for (int i = 0; i < n; ++i) k += s[i] * mul[i];
      return k;
    };

    auto decode = [&](uint64_t key, std::vector<uint64_t> &out) {
      for (int i = n - 1; i >= 0; --i) {
        const uint64_t base = goal[i] + 1ULL;
        out[i] = (key / mul[i]) % base;
      }
    };

    // Precompute per-dimension max progress per press for heuristic
    std::vector<uint64_t> maxDelta(n, 0);
    for (int bi = 0; bi < m; ++bi) {
      for (int i = 0; i < n; ++i) {
        maxDelta[i] = std::max(maxDelta[i], deltas[bi][i]);
      }
    }

    auto heuristic = [&](const std::vector<uint64_t> &state) -> uint32_t {
      uint32_t h = 0;
      for (int i = 0; i < n; ++i) {
        if (state[i] > goal[i]) return std::numeric_limits<uint32_t>::max(); // shouldn't happen
        const uint64_t rem = goal[i] - state[i];
        if (rem == 0) continue;

        if (maxDelta[i] == 0) {
          // this component can never increase -> unreachable
          return std::numeric_limits<uint32_t>::max();
        }

        const uint64_t need = (rem + maxDelta[i] - 1ULL) / maxDelta[i]; // ceil
        if (need > std::numeric_limits<uint32_t>::max()) return std::numeric_limits<uint32_t>::max();
        h = std::max(h, (uint32_t)need);
      }
      return h;
    };

    const uint64_t startKey = 0;
    const uint64_t goalKey = encode(goal);

    // A* open set
    struct Node {
      uint64_t key;
      uint32_t g;
      uint32_t f;
    };
    struct BySmallestF {
      bool operator()(const Node &a, const Node &b) const {
        return a.f > b.f; // min-heap behavior via priority_queue
      }
    };

    std::priority_queue<Node, std::vector<Node>, BySmallestF> open;
    std::unordered_map<uint64_t, uint32_t> gScore;
    std::unordered_map<uint64_t, Prev> parent;

    gScore.reserve(200000);
    parent.reserve(200000);

    std::vector<uint64_t> cur(n, 0), next(n, 0);

    const uint32_t h0 = heuristic(cur);
    if (h0 == std::numeric_limits<uint32_t>::max()) return {};

    gScore.emplace(startKey, 0);
    parent.emplace(startKey, Prev{startKey, UINT16_MAX});
    open.push(Node{startKey, 0, h0});

    while (!open.empty()) {
      const Node node = open.top();
      open.pop();

      // Skip stale entries (classic A* optimization)
      auto itG = gScore.find(node.key);
      if (itG == gScore.end() || itG->second != node.g) continue;

      if (node.key == goalKey) {
        return reconstruct(goalKey, startKey, parent);
      }

      decode(node.key, cur);

      for (uint16_t bi = 0; bi < (uint16_t)m; ++bi) {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
          const uint64_t v = cur[i] + deltas[bi][i];
          if (v > goal[i]) { ok = false; break; }
          next[i] = v;
        }
        if (!ok) continue;

        const uint64_t nk = encode(next);
        const uint32_t ng = node.g + 1;

        const uint32_t nh = heuristic(next);
        if (nh == std::numeric_limits<uint32_t>::max()) continue;

        auto it = gScore.find(nk);
        if (it == gScore.end() || ng < it->second) {
          gScore[nk] = ng;
          parent[nk] = Prev{node.key, bi};
          open.push(Node{nk, ng, ng + nh});
        }
      }
    }

    return {};
  }

} // namespace D10
