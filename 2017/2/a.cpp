#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int checksum{};
  std::string line;
  while (std::getline(fin, line)) {
    std::stringstream ss;
    ss<<line;
    int max,min;
    int val;
    ss>>val;
    max = val;
    min = val;
    while (ss>>val) {
      max = std::max(val,max);
      min = std::min(val, min);
    }
    checksum += max-min;
  }
  std::cout<<checksum;
  return 0;
}
