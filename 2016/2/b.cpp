#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string str;
  int x{}, y{2};
  std::map<std::pair<int, int>, char> map;
  int pos{};
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < 5; i++) {
      if (std::abs(i - 2) + std::abs(j - 2) <= 2) {
        map[std::make_pair(i, j)] = "123456789ABCD"[pos++];
      }
    }
  }
  while (std::getline(fin, str)) {
    for (char c : str) {
      int newx = x, newy = y;
      switch (c) {
      case 'U':
        newy = std::max(y - 1, 0);
        break;
      case 'D':
        newy = std::min(y + 1, 4);
        break;
      case 'L':
        newx = std::max(x - 1, 0);
        break;
      case 'R':
        newx = std::min(x + 1, 4);
        break;
      }
      if (std::abs(newx - 2) + std::abs(newy - 2) <= 2) {
        x = newx;
        y = newy;
      }
    }
    std::cout << map[std::make_pair(x, y)];
  }
  return 0;
}
