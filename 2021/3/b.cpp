#include <algorithm>
#include <bitset>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int len;
  std::string str;
  fin >> str;
  len = str.size();
  fin.clear();
  fin.seekg(0, fin.beg);
  std::vector<std::uint_least16_t> co2;
  std::vector<std::uint_least16_t> o2;
  while (std::getline(fin, str)) {
    uint_least16_t val{};
    for (char c : str) {
      val = val * 2 + c - '0';
    }
    co2.push_back(val);
    o2.push_back(val);
  }
  int count[2]{};
  for (size_t i = 0; i < len; i++) {
    for (uint_least16_t var : co2) {
      count[((var >> (len - i - 1)) & 1)]++;
    }
    if (co2.size() > 1) {
      co2.erase(std::remove_if(co2.begin(), co2.end(),
                              [&](int val) {
                                return ((count[1] >= count[0])
                                           ? [](bool b) { return b; }
                                           : [](bool b) {
                                               return !b;
                                             })((val >> (len - i - 1)) & 1);
                              }),
               co2.end());
    }
    count[0] = 0;
    count[1] = 0;
    for (uint_least16_t var : o2) {
      count[((var >> (len - i - 1)) & 1)]++;
    }
    if (o2.size() > 1) {
      o2.erase(std::remove_if(o2.begin(), o2.end(),
                              [&](int val) {
                                return ((count[1] < count[0])
                                           ? [](bool b) { return b; }
                                           : [](bool b) {
                                               return !b;
                                             })((val >> (len - i - 1)) & 1);
                              }),
               o2.end());
    }
    count[0] = 0;
    count[1] = 0;
  }
  std::cout<<(co2[0]*o2[0]);
  return 0;
}
