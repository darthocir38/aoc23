
#include <sstream>
#include <string>

namespace d12 {

int p1(const char *data) {
  std::stringstream stream{data};
  std::string line;
  int sum = 0;
  while (std::getline(stream, line, '\n')) {
    //sum += p1_get_num_of_line(line);
  }
  return sum;
}

int p2(const char *data) {
  std::stringstream stream{data};
  std::string line;
  int sum = 0;
  while (std::getline(stream, line, '\n')) {
    //sum += p2_get_num_of_line(line);
  }
  return sum;
}

} // namespace d4
