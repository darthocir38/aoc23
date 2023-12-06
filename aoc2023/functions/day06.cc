
#include <algorithm>
#include <execution>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

namespace d06
{

std::vector<int> get_numbers(std::string const& line)
{
	auto             colon_idx = line.find(':');
	auto             values    = line.substr(colon_idx + 1, line.size());
	std::vector<int> result;
	std::string      tmp;
	bool             in_val = false;
	for (auto i = 0; i < values.size(); i++)
	{
		if (values[i] == ' ')
		{
			if (in_val)
			{
				result.push_back(std::stoi(tmp));
				in_val = false;
				tmp.clear();
			}
			continue;
		}
		in_val = true;
		tmp.push_back(values[i]);
	}
	if (in_val) { result.push_back(std::stoi(tmp)); }
	return result;
}

long get_number(std::string const& line)
{
	auto        colon_idx = line.find(':');
	auto        values    = line.substr(colon_idx + 1, line.size());
	std::string tmp;
	for (auto i = 0; i < values.size(); i++)
	{
		if (values[i] == ' ') { continue; }
		tmp.push_back(values[i]);
	}
	return std::stol(tmp);
}

std::vector<std::pair<int, int>>
    build_pairs(std::vector<int> const& t, std::vector<int> const& d)
{
	auto result = std::vector<std::pair<int, int>>();
	result.reserve(t.size());
	for (auto i = 0; i < t.size(); i++) { result.emplace_back(t[i], d[i]); }
	return result;
}

int p1(const char* data)
{
	std::stringstream stream{ data };
	std::string       line_time;
	std::string       line_distance;
	std::getline(stream, line_time, '\n');
	std::getline(stream, line_distance, '\n');
	auto pairs =
	    build_pairs(get_numbers(line_time), get_numbers(line_distance));
	std::vector<int> winners;
	winners.reserve(pairs.size());

	std::transform(
	    /*std::execution::par_unseq,*/
	    pairs.cbegin(),
	    pairs.cend(),
	    std::back_inserter(winners),
	    [&](auto const& p) {
		    // spdlog::info("hello vs: ");
		    int maxtime  = p.first;
		    int winner_d = p.second;
		    int winners  = 0;
		    for (auto i = 1; i < maxtime; i++)
		    {
			    auto go_time = maxtime - i;
			    auto dist    = go_time * (i * 1);
			    if (dist > winner_d) { winners++; }
			    /* spdlog::info(
			         "charge_time: {} distance: {} winner_d {}, amount {}",
			         i,
			         dist,
			         winner_d,
			         winners);*/
		    }
		    return winners;
	    });

	//	spdlog::info("winners {}", winners.size());
	// for (auto winner : winners) { spdlog::info("winners {}", winner); }

	return std::accumulate(
	    winners.begin(), winners.end(), 1, [](auto const& a, auto const& b) {
		    return a * b;
	    });
}

int p2(const char* data)
{
	std::stringstream stream{ data };
	std::string       line_time;
	std::string       line_distance;
	std::getline(stream, line_time, '\n');
	std::getline(stream, line_distance, '\n');

	auto maxtime  = get_number(line_time);
	auto winner_d = get_number(line_distance);

	int winners = 0;

	for (auto i = 1; i < maxtime; i++)
	{
		auto go_time = maxtime - i;
		auto dist    = go_time * (i * 1);
		if (dist > winner_d) { winners++; }
		/* spdlog::info(
		     "charge_time: {} distance: {} winner_d {}, amount {}",
		     i,
		     dist,
		     winner_d,
		     winners);*/
	}

	//	spdlog::info("winners {}", winners.size());
	// for (auto winner : winners) { spdlog::info("winners {}", winner); }

	return winners;
}

} // namespace d06
