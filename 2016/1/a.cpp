#include <ctype.h>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int dir = 0;
  int x{}, y{};
  char c;
  int dist{};
  while (fin >> c) {
    if (c == ',') {
      switch (dir) {
      case 0:
        y += dist;
        break;
      case 1:
        x += dist;
        break;
      case 2:
        y -= dist;
        break;
      case 3:
        x -= dist;
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
