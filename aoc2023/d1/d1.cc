#include "input.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

static auto const nums = "0123456789";
static std::vector<std::string> const string_nums = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

unsigned p1_get_num_of_line(std::string const &line) {

  auto first_digit = line.find_first_of(nums);
  auto last_digit = line.find_last_of(nums);

  return std::stoi(std::string{line[first_digit], line[last_digit]});
}

unsigned p2_get_num_of_line(std::string const &line) {

  auto get_char = [&](std::string const &line, bool first) {
    auto digit_idx = first ? line.find_first_of(nums) : line.find_last_of(nums);

    auto pos = digit_idx != std::string::npos ? digit_idx
               : first ? std::numeric_limits<unsigned long>::max()
                       : std::numeric_limits<unsigned long>::min();
    char value = digit_idx != std::string::npos ? line[digit_idx] : 0;

    for (size_t i = 0; i < string_nums.size(); i++) {
      auto found =
          first ? line.find(string_nums[i]) : line.rfind(string_nums[i]);
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
    return value;
  };

  return std::stoi(std::string{get_char(line, true), get_char(line, false)});
};

int main() {
  std::stringstream ss(day01);
  std::string line;
  int sum_p1 = 0;
  int sum_p2 = 0;

  while (std::getline(ss, line, '\n')) {
    sum_p1 += p1_get_num_of_line(line);
    sum_p2 += p2_get_num_of_line(line);
  }

  std::cout << "p1: " << sum_p1 << " p2: " << sum_p2 << std::endl;
}
