#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  bool board[1000][1000]{};
  std::string str;
  while (std::getline(fin, str)) {
    bool (*op)(bool);
    std::stringstream ss;
    ss << str;
    std::string state;
    ss >> state;
    if (state == "toggle") {
      op = [](bool b) { return !b; };
    } else {
      ss >> state;
      if (state == "on") {
        op = [](bool) { return true; };
      } else {
        op = [](bool) { return false; };
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
      if (board[x][y])
        count++;
    }
  }
  std::cout<<count;
  return 0;
}
