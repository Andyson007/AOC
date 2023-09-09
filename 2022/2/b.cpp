#include <fstream>
#include <iostream>
#include <set>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string str;
  int pos{};
  std::set<int> visited;
  visited.insert(0);
  while (true) {
    while (std::getline(fin, str)) {
      pos += (str[0] == '+' ? [](int a) { return a; } : [](int a) {
        return -a;
      })(std::stoi(str.substr(1, str.size() - 1)));
      if (visited.find(pos) == visited.end()) {
        visited.insert(pos);
      } else {
        std::cout << pos;
        return 0;
      }
    }
    fin.clear();
    fin.seekg(0, fin.beg);
  }
  return 0;
}
