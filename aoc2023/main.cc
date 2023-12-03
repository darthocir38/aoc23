#include <iostream>

#include "input.h"

#include "d1/main.cc"
#include "d2/main.cc"
#include "d3/main.cc"


int main() {

std::cout << "Hello Advent of code" << std::endl;
std::cout << "Day 1: Part 1: "<< d1::p1(day01) << " Part 2: " << d1::p2(day01) << std::endl;
std::cout << "Day 1: Part 1: "<< d2::p1(day02) << " Part 2: " << d2::p2(day02) << std::endl;
std::cout << "Day 1: Part 1: "<< d3::p1(day03) << " Part 2: " << d3::p2(day03) << std::endl;

return 0;
}
