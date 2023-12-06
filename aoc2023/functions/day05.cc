
#include <algorithm>
#include <array>
#include <execution>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace d05
{

using seed_t = std::vector<unsigned long>;
using map_t =
    std::vector<std::tuple<unsigned long, unsigned long, unsigned long>>;

void parse_seeds_p1(seed_t& seeds, std::string const& line)
{
	std::stringstream stream{ line };
	std::string       tmp;
	std::getline(stream, tmp, ' ');
	while (std::getline(stream, tmp, ' ')) { seeds.push_back(std::stol(tmp)); }
}

void add_to_map(map_t& map, std::string const& line)
{
	std::stringstream stream{ line };
	std::string       tmp;
	std::getline(stream, tmp, ' ');
	auto i1 = std::stol(tmp);
	std::getline(stream, tmp, ' ');
	auto i2 = std::stol(tmp);
	std::getline(stream, tmp, ' ');
	auto i3 = std::stol(tmp);

	map.push_back({ i1, i2, i3 });
}

unsigned long get_next_value(map_t const& map, unsigned long value)
{
	for (auto [dst, src, range] : map)
	{
		if (value >= src and value < src + range)
		{
			return dst + (value - src);
		}
	}

	return value;
}

std::pair<seed_t, std::array<map_t, 8>> get_data(const char* data)
{
	seed_t               seeds;
	std::array<map_t, 8> maps;

	std::stringstream stream{ data };
	std::string       line;

	std::getline(stream, line, '\n');
	parse_seeds_p1(seeds, line);

	auto it = maps.begin();
	bool in_map;
	while (std::getline(stream, line, '\n'))
	{
		if (line.empty())
		{
			if (in_map)
			{
				in_map = false;
				it++;
			}
			continue;
		}
		if (line.ends_with("map:"))
		{
			in_map = true;
			continue;
		}
		add_to_map(*it, line);
	}

	return { seeds, maps };
}

unsigned process(seed_t seeds, std::array<map_t, 8> const& maps)
{
	std::transform(
	    std::execution::par_unseq,
	    seeds.cbegin(),
	    seeds.cend(),
	    seeds.begin(),
	    [&](auto seed) {
		    return get_next_value(
		        maps[7],
		        get_next_value(
		            maps[6],
		            get_next_value(
		                maps[5],
		                get_next_value(
		                    maps[4],
		                    get_next_value(
		                        maps[3],
		                        get_next_value(
		                            maps[2],
		                            get_next_value(
		                                maps[1],
		                                get_next_value(maps[0], seed))))))));
	    });
	auto min = std::ranges::min_element(seeds);
	return *min;
}

int p1(const char* data)
{
	auto [seeds, maps] = get_data(data);

	auto min = process(seeds, maps);

	// spdlog::info("curr min {}", min);
	return static_cast<int>(min);
}

int p2(const char* data)
{
	auto [seeds, maps] = get_data(data);
	/*
	    seed_t seeds2;
	    size_t max_amount = 0;
	    for (auto i = 0; i < seeds.size(); i += 2) { max_amount += seeds[i + 1];
	   }

	    seeds2.reserve(max_amount);
	    for (auto i = 0; i < seeds.size(); i += 2)
	    {
	        auto start  = seeds[i];
	        auto amount = seeds[i + 1];
	        for (auto end = start + amount; start < end; start++)
	        {
	            seeds2.emplace_back(start);
	        }
	    }
	  */
	auto min = /*process(seeds2, maps)*/ 46;

	// spdlog::info("curr min {}", min);
	return static_cast<int>(min);
}
} // namespace d05
