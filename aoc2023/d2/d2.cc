#include "input.h"
#include <iostream>
#include <map>
#include <sstream>
#include <string>

signed get_game_id(auto game_str) {
  return std::stoi(game_str.substr(game_str.find(' '), game_str.size()));
}

static const std::map<std::string, signed> limits{
    {"red", 12}, {"green", 13}, {"blue", 14}};

signed get_number_of_line_p1(std::string const &line) {
  auto colon_idx = line.find(':');
  auto game_id = get_game_id(line.substr(0, colon_idx));

  std::stringstream all_results(line.substr(colon_idx + 1, line.size()));
  std::string tmp;

  while (getline(all_results, tmp, ';')) {
    std::stringstream result(tmp);
    std::string tmp2;
    while (getline(result, tmp2, ',')) {
      std::cout << "id: " << game_id << " a result: " << tmp2 << std::endl;
      auto split_idx = tmp2.rfind(' ');
      auto amount = std::stoi(tmp2.substr(1, split_idx));
      auto color = tmp2.substr(split_idx + 1, tmp2.length());

      std::cout << "a result color: " << color << " amount: " << amount
                << std::endl;

      auto limit = limits.at(color);
      if (amount > limit)
        return 0;
    }
  }
  return game_id;
}

int main() {
  std::stringstream ss(day02);
  std::string line;

  signed sum = 0;

  while (std::getline(ss, line, '\n')) {
    sum += get_number_of_line_p1(line);
  }

  std::cout << "p1: " << sum << std::endl;
}
