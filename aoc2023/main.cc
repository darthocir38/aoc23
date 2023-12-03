#include <spdlog/spdlog.h>

#include "functions.h"
#include "input.h"

int main() {
  spdlog::info("Hello Advent of code!");
  for (auto i = 0u; i < functions.size(); i++) {
    spdlog::info("Day {}: Part 1: {} Part 2: {}", i,
                 functions[i].first(inputs[i]), functions[i].second(inputs[i]));
  }
  return 0;
}
