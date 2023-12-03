#include <iostream>
#include <map>
#include <sstream>
#include <string>


namespace d2{

std::pair<signed, std::string> get_game(std::string const& line) {

  auto colon_idx = line.find(':');
  auto id_str = line.substr(0, colon_idx);
  return {std::stoi(id_str.substr(id_str.find(' '), id_str.size())),
          line.substr(colon_idx + 1, line.size())};
}

static const std::map<std::string, signed> limits{
    {"red", 12}, {"green", 13}, {"blue", 14}};

signed get_number_of_line_p1(std::string const &line) {
  auto [game_id, game_str] = get_game(line);

  std::stringstream all_results(game_str);
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

signed get_number_of_line_p2(std::string const &line) {
  auto [game_id, game_str] = get_game(line);

  std::stringstream all_results(game_str);
  std::string tmp;

  std::map<std::string, signed> requirements{
      {"red", 0}, {"green", 0}, {"blue", 0}};

  while (getline(all_results, tmp, ';')) {
    std::stringstream result(tmp);
    std::string tmp2;

    while (getline(result, tmp2, ',')) {
      auto split_idx = tmp2.rfind(' ');
      auto amount = std::stoi(tmp2.substr(1, split_idx));
      auto color = tmp2.substr(split_idx + 1, tmp2.length());

      // std::cout << "a result color: " << color << " amount: " << amount
      //           << std::endl;
      requirements[color] = std::max(requirements[color], amount);
    }
  }
  auto pwr = requirements["red"] * requirements["green"] * requirements["blue"];

  std::cout << game_str << " req r:" << requirements["red"]
            << " g:" << requirements["green"] << " b:" << requirements["blue"]
            << "pwr: " << pwr << std::endl;
  return pwr;
}

int p1(std::string data) {
  std::stringstream ss(data);
  std::string line;

  signed sum = 0;

  while (std::getline(ss, line, '\n')) {
    sum += get_number_of_line_p1(line);
  }
  return sum;
}

int p2(std::string data) {
  std::stringstream ss(data);
  std::string line;

  signed sum = 0;

  while (std::getline(ss, line, '\n')) {
    sum += get_number_of_line_p2(line);
  }
  return sum;
}

}