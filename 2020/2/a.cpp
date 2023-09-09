#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string line;
  int tot{};
  while (std::getline(fin, line)) {
    std::stringstream ss;
    std::string str;
    ss << line;
    int min, max;
    char c;
    char temp;
    ss >> min >> temp >> max >> c >> temp >> str;
    int count{};
    for (char ch : str) {
      if (ch == c) {
        count++;
      }
    }
    if (count >= min && count <= max) {
      tot++;
    }
  }
  std::cout<<tot;
  return 0;
}
