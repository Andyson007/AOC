// This program finds the sum of all the red tagged elements
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string str;
  std::vector<std::pair<int, int>> ranges;
  getline(fin, str);
  std::regex r("\"red\"");

  for (std::sregex_iterator i = std::sregex_iterator(str.begin(), str.end(), r);
       i != std::sregex_iterator(); ++i) {
    std::smatch m = *i;
    // std::cout << m.str() << " at position " << m.position() << '\n';
    int start, end;
    bool isArray{};
    int level = 1;
    for (size_t j = m.position();; j--) {
      if (str[j] == '[' && level == 1) {
        isArray = true;
        break;
      } else if (str[j] == '{')
        level--;
      else if (str[j] == '}')
        level++;
      if (level == 0) {
        start = j;
        break;
      }
    }
    if (isArray)
      continue;
    level = 1;
    for (size_t j = m.position();; j++) {
      if (str[j] == '}')
        level--;
      else if (str[j] == '{')
        level++;
      if (level == 0) {
        end = j;
        break;
      }
    }
    if (!ranges.empty())
      if (ranges[ranges.size() - 1].second >= end)
        continue;
    while (!ranges.empty() && (ranges[ranges.size() - 1].first >= start)) {
      ranges.pop_back();
    }
    ranges.push_back(std::make_pair(start, end));
  }
  for (auto [a, b] : ranges) {
    for (size_t i = a; i < b; i++) {
      std::cout << str[i];
    }
    std::cout << '\n';
  }
  int count{};
  for (auto [a, b] : ranges) {
    int curr{};
    bool isNegative{};
    for (size_t i = a; i <= b; i++) {
      char c = str[i];
      if (isdigit(c)) {
        curr = 10 * curr + c - '0';
      } else {
        if (isNegative)
          count -= curr;
        else
          count += curr;
        curr = 0;
        isNegative = (c == '-');
      }
    }
    count += curr;
    std::cout << a << ", " << b << ": " << count << '\n';
  }
  std::cout << count;
  return 0;
}
