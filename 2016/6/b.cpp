#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::vector<std::map<char, int>> vec;
  std::string str;
  bool first{true};
  while (fin >> str) {
    if (first) {
      for (size_t i = 0; i < str.size(); i++) {
        std::map<char, int> temp;
        vec.push_back(temp);
      }
      first = false;
    }
    for (size_t i = 0; i < str.size(); i++) {
      vec[i][str[i]]++;
    }
  }
  for (std::map<char, int> &map : vec) {
    char maxchar;
    int minval=100; //idk why this didn't work: str.size()+1 ;
    for (auto [a, b] : map) {
      if (minval > b) {
        minval = b;
        maxchar = a;
      }
    }
    std::cout << maxchar;
  }
  return 0;
}
