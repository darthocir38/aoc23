
#include <catch2/catch_test_macros.hpp>

#include "functions.h"

TEST_CASE("D1P1") {
  auto data = R"(1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet)";

  REQUIRE(d01::p1(data) == 142);
}

TEST_CASE("D1P2") {
  auto data = R"(two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen)";

  REQUIRE(d01::p2(data) == 281);
}

TEST_CASE("D2P1") {
  auto data =
      R"(Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green)";

  REQUIRE(d02::p1(data) == 8);
}

TEST_CASE("D2P2") {
  auto data =
      R"(Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green)";

  REQUIRE(d02::p2(data) == 2286);
}

TEST_CASE("D3P1") {
  auto data =
      R"(467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..)";

  REQUIRE(d03::p1(data) == 4361);
}

TEST_CASE("D3P2") {
  auto data =
      R"(467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..)";

  REQUIRE(d03::p2(data) == 467835);
}
