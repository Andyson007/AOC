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
  std::vector<std::uint_least16_t> vals;
  while (std::getline(fin, str)) {
    uint_least16_t val{};
    for (char c : str) {
      val = val * 2 + c - '0';
    }
    vals.push_back(val);
  }
  uint_least16_t gamma{};
  uint_least16_t epsilon{};
  int count[2]{};
  for (size_t i = 0; i < len; i++) {
    for (uint_least16_t var : vals) {
      count[((var >> (len - i - 1)) & 1)]++;
    }
    if (count[1] > count[0]){
      gamma |= 1 << (len - i - 1);
    }else{
      epsilon |= 1 << (len - i - 1);
    }
  count[0] = 0;
  count[1] = 0;
  }
  std::cout<<(epsilon*gamma);
  return 0;
}
