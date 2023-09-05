#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  char board[1000][1000]{};
  std::string str;
  while (std::getline(fin, str)) {
    int (*op)(int);
    std::stringstream ss;
    ss << str;
    std::string state;
    ss >> state;
    if (state == "toggle") {
      op = [](int b) { return b+2; };
    } else {
      ss >> state;
      if (state == "on") {
        op = [](int b) { return b+1; };
      } else {
        op = [](int b) { return b?(b-1):0; };
      }
    }
    int startx, starty, endx, endy;
    std::string d;
    char c;
    ss >> startx >> c >> starty >> d >> endx >> c >> endy;
    for (size_t x = startx; x <= endx; x++) {
      for (size_t y = starty; y <= endy; y++) {
        board[x][y] = op(board[x][y]);
      }
    }
  }
  int count{};
  for (size_t x = 0; x <= 999; x++) {
    for (size_t y = 0; y <= 999; y++) {
      count+=board[x][y];
    }
  }
  std::cout<<count;
  return 0;
}
