#include <spdlog/spdlog.h>

#include "input.h"

#include "d1/main.cc"
#include "d2/main.cc"
#include "d3/main.cc"


int main() {
spdlog::info("Hello Advent of code!");
spdlog::info("Day 1: Part 1: {} Part 2: {}",d1::p1(day01), d1::p2(day01) );
spdlog::info("Day 2: Part 1: {} Part 2: {}",d2::p1(day02), d2::p2(day02) );
spdlog::info("Day 3: Part 1: {} Part 2: {}",d3::p1(day03), d3::p2(day03) );
return 0;
}
