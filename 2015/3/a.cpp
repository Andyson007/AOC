#include <fstream>
#include <iostream>
#include <set>
#include <utility>


int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  char c;
  int x{},y{};
  std::set<std::pair<int, int>> set;
  while (fin>>c) {
    if(c=='^') y += 1;
    if(c=='>') x += 1;
    if(c=='v') y -= 1;
    if(c=='<') x -= 1;
    set.insert(std::make_pair(x, y));
  }
  std::cout<<set.size();
}
