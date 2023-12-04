
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <span>
#include <sstream>
#include <string>
#include <string_view>

namespace d04
{

std::pair<signed, std::string> get_card(std::string const& line)
{
	auto colon_idx = line.find(':');
	auto id_str    = line.substr(0, colon_idx);
	return { std::stoi(id_str.substr(id_str.find(' '), id_str.size())),
		     line.substr(colon_idx + 1, line.size()) };
}

std::pair<std::string, std::string> splitt_card(std::string const& card)
{
	auto pipe_idx  = card.find('|');
	auto winners   = card.substr(0, pipe_idx);
	auto scratched = card.substr(pipe_idx + 1, card.size());

	return { winners, scratched };
}

int p1_get_num_of_line(std::string const& line)
{
	auto const& [game_id, card_str]  = get_card(line);
	auto const& [winners, scratched] = splitt_card(card_str);

	auto value = 0;

	for (auto i = 0; i < scratched.size(); i += 3)
	{
		std::string_view num{ begin(scratched) + i,
			                  std::begin(scratched) + i + 3 };
		if (winners.find(num) == std::string::npos) { continue; }
		if (value == 0)
		{
			value = 1;
			continue;
		}
		value *= 2;
	}

	return value;
}

int p1(const char* data)
{
	std::stringstream stream{ data };
	std::string       line;
	int               sum = 0;
	while (std::getline(stream, line, '\n'))
	{
		sum += p1_get_num_of_line(line);
	}
	return sum;
}

int p2(const char* data)
{
	std::stringstream stream{ data };
	std::string       line;
	int               sum = 0;
	while (std::getline(stream, line, '\n'))
	{
		// sum += p2_get_num_of_line(line);
	}
	return sum;
}

} // namespace d04
