#include "input.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

void p1() {

  /*
  const std::string day01 = R"(1abc2
  pqr3stu8vwx
  a1b2c3d4e5f
  treb7uchet)";
  */

  auto get_num_of_line = [](std::string const &line) {
    auto const nums = "0123456789";
    auto first_digit = line.find_first_of(nums);
    auto last_digit = line.find_last_of(nums);

    return std::stoi(std::string{line[first_digit], line[last_digit]});
  };

  std::stringstream ss(day01);
  std::string line;
  int sum = 0;
  while (std::getline(ss, line, '\n')) {
    sum += get_num_of_line(line);
  }

  std::cout << sum << std::endl;
}

void p2() {

  const std::string day01p2 = R"(two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen)";

  auto get_char = [](std::string const &line, bool first) {
    auto const nums = "0123456789";
    std::vector<std::string> const string_nums = {
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    auto digit_idx = first ? line.find_first_of(nums) : line.find_last_of(nums);
    auto pos = digit_idx != std::string::npos ? digit_idx
               : first ? std::numeric_limits<unsigned long>::max()
                       : std::numeric_limits<unsigned long>::min();
    char value = digit_idx != std::string::npos ? line[digit_idx] : 0;

    for (size_t i = 0; i < string_nums.size(); i++) {
      auto found = line.find(string_nums[i]);
      if (found == std::string::npos) {
        continue;
      }

      if (first) {
        if (found < pos) {
          pos = found;
          value = nums[i + 1];
        }
      } else {
        if (found > pos) {
          pos = found;
          value = nums[i + 1];
        }
      }
    }
    // std::cout << line << " : " << pos << ": " << value << std::endl;
    return value;
  };

  auto get_num_of_line = [&](std::string const &line) {
    std::cout << line << " : "
              << std::string{get_char(line, true), get_char(line, false)}
              << std::endl;

    return std::stoi(std::string{get_char(line, true), get_char(line, false)});
  };

  std::stringstream ss(day01p2);
  std::string line;
  int sum = 0;
  while (std::getline(ss, line, '\n')) {
    sum += get_num_of_line(line);
  }

  std::cout << sum << std::endl;
}

int main() { p2(); }