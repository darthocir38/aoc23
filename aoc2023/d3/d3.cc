#include "input.h"
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

struct Num {
  int line;
  int start;
  int end;
  std::string value;
};

struct Symbol {
  int line;
  int start;
};

enum class State { idle, number };

int main() {

  std::vector<Num> numbers;
  std::vector<Symbol> symbols;

  std::stringstream ss(data);
  std::string line;

  signed sum = 0;

  auto line_nr = 0;
  while (std::getline(ss, line, '\n')) {
    line_nr++;
    State state = State::idle;

    for (auto idx = 0u; idx < line.length(); idx++) {
      auto c = line[idx];
      // std::cout << "process " << line_nr << " idx " << idx << " c:" << c
      //           << std::endl;

      if (std::isdigit(c)) {
        if (state == State::idle) {
          // std::cout << "start number" << std::endl;
          state = State::number;
          numbers.emplace_back(line_nr, idx, idx, std::string{c});
        } else {
          auto &curr_num = numbers.back();
          // std::cout << "continue number:" << curr_num.value << std::endl;

          curr_num.end++;
          curr_num.value.push_back(c);
        }
        continue;
      }
      state = State::idle;
      if (c == '.') {
        continue;
      } else {
        symbols.emplace_back(line_nr, idx);
      }
    }
  }

  for (auto symbol : symbols) {
    std::cout << "process symbol at " << symbol.line << ":" << symbol.start
              << std::endl;
    for (auto const &num : numbers) {
      if (std::abs(symbol.line - num.line) > 1) {
        continue;
      }
      if (symbol.start < (num.start - 1) or symbol.start > (num.end + 1)) {
        continue;
      }
      sum += std::stoi(num.value);
      std::cout << "found number:" << num.value << std::endl;
    }
  }

  std::cout << "p1: " << sum << std::endl;
}
