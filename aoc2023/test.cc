
#include "functions.h"

#include <catch2/catch_test_macros.hpp>
#include <spdlog/spdlog.h>

TEST_CASE("D1P1")
{
	auto data = R"(1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet)";

	REQUIRE(d01::p1(data) == 142);
}

TEST_CASE("D1P2")
{
	auto data = R"(two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen)";

	REQUIRE(d01::p2(data) == 281);
}

TEST_CASE("D2")
{
	auto data =
	    R"(Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green)";

	REQUIRE(d02::p1(data) == 8);
	REQUIRE(d02::p2(data) == 2286);
}

TEST_CASE("D3")
{
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
	REQUIRE(d03::p2(data) == 467835);
}

TEST_CASE("D4")
{
	auto data =
	    R"(Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53
Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19
Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1
Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83
Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36
Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11)";

	REQUIRE(d04::p1(data) == 13);
	REQUIRE(d04::p2(data) == 30);
}

TEST_CASE("D5")
{
	spdlog::set_level(spdlog::level::debug);
	auto data =
	    R"(seeds: 79 14 55 13

seed-to-soil map:
50 98 2
52 50 48

soil-to-fertilizer map:
0 15 37
37 52 2
39 0 15

fertilizer-to-water map:
49 53 8
0 11 42
42 0 7
57 7 4

water-to-light map:
88 18 7
18 25 70

light-to-temperature map:
45 77 23
81 45 19
68 64 13

temperature-to-humidity map:
0 69 1
1 0 69

humidity-to-location map:
60 56 37
56 93 4)";

	REQUIRE(d05::p1(data) == 35);
	REQUIRE(d05::p2(data) == 46);
}

TEST_CASE("D6")
{
	auto data =
	    R"(Time:      7  15   30
Distance:  9  40  200)";

	spdlog::set_level(spdlog::level::debug);
	REQUIRE(d06::p1(data) == 288);
	REQUIRE(d06::p2(data) == 71503);
}
