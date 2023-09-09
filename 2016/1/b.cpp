#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int dir = 0;
  int x{}, y{};
  char c;
  int dist{};
  std::vector<std::pair<int, int>> visited;
  while (fin >> c) {
    if (c == ',') {
      int max{};
      switch (dir) {
      case 0:
        max = y+dist;
        for (; y<max; y++) {
          if(std::find(visited.begin(), visited.end(), std::make_pair(x, y))!=visited.end())
            std::cout<<x<<' '<<y<<'\n';
          visited.push_back(std::make_pair(x, y));
        }
        break;
      case 1:
        max = x+dist;
        for (; x<max; x++) {
          if(std::find(visited.begin(), visited.end(), std::make_pair(x, y))!=visited.end())
            std::cout<<x<<' '<<y<<'\n';
          visited.push_back(std::make_pair(x, y));
        }
        break;
      case 2:
        max = y-dist;
        for (; y>max; y--) {
          if(std::find(visited.begin(), visited.end(), std::make_pair(x, y))!=visited.end())
            std::cout<<x<<' '<<y<<'\n';
          visited.push_back(std::make_pair(x, y));
        }
        break;
      case 3:
        max = x-dist;
        for (; x>max; x--) {
          if(std::find(visited.begin(), visited.end(), std::make_pair(x, y))!=visited.end())
            std::cout<<x<<' '<<y<<'\n';
          visited.push_back(std::make_pair(x, y));
        }
        break;
      }
      dist = 0;
    }
    if (c == 'L') {
      dir = (dir + 3) % 4;
    } else if (c == 'R') {
      dir = (dir + 1) % 4;
    }
    if (isdigit(c)) {
      dist = 10 * dist + c - '0';
    }
  }
  std::cout << x << ' ' << y;
  return 0;
}
