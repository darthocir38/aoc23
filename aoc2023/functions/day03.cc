#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

namespace d03 {

struct Num {
  int line;
  int start;
  int end;
  std::string value;
};

struct Symbol {
  int line;
  int start;
  char c;
};

enum class State { idle, number };


std::pair<std::vector<Num>, std::vector<Symbol>> get_data(std::string const& data)
{
  std::vector<Num> numbers;
  std::vector<Symbol> symbols;

  std::stringstream ss(data);
  std::string line;

  signed sum = 0;
  auto line_nr = 0;
  while (std::getline(ss, line, '\n')) {
    line_nr++;
    State state = State::idle;

    for (auto idx = 0; idx < line.length(); idx++) {
      auto c = line[idx];

      if (std::isdigit(c)) {
        if (state == State::idle) {
          state = State::number;
          numbers.push_back({line_nr, idx, idx, std::string{c}});
        } else {
          auto &curr_num = numbers.back();

          curr_num.end++;
          curr_num.value.push_back(c);
        }
        continue;
      }
      state = State::idle;
      if (c == '.') {
        continue;
      } else {
        symbols.push_back({line_nr, idx, c});
      }
    }
  }
  return {numbers, symbols};
}




int p1(const char* data){
  auto const& [numbers,symbols] = get_data(data);
  int sum = 0;

  for (auto symbol : symbols) {

    for (auto const &num : numbers) {
      if (std::abs(symbol.line - num.line) > 1) {
        continue;
      }
      if (symbol.start < (num.start - 1) or symbol.start > (num.end + 1)) {
        continue;
      }
      sum += std::stoi(num.value);
    }
  }

return sum;

}

int p2(const char* data)
{
  auto const& [numbers,symbols] = get_data(data);

  int sum = 0;
  for (auto symbol : symbols) {
    if (symbol.c != '*') {
      continue;
    }

    std::vector<Num> ratios;
    for (auto const &num : numbers) {
      if (std::abs(symbol.line - num.line) > 1) {
        continue;
      }
      if (symbol.start < (num.start - 1) or symbol.start > (num.end + 1)) {
        continue;
      }
      ratios.push_back(num);
    }
    if (ratios.size() < 2) {
      continue;
    }
    unsigned pwr = 1;
    for (auto const &r : ratios) {
      pwr *= std::stoi(r.value);
    }
    sum += pwr;
  }
return sum;
}


}