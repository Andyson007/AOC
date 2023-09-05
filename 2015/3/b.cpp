#include <fstream>
#include <iostream>
#include <set>
#include <utility>


int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  char c;
  int x{},y{};
  int rx{},ry{};
  std::set<std::pair<int, int>> set;
  while (fin>>c) {
    if(c=='^') y += 1;
    if(c=='>') x += 1;
    if(c=='v') y -= 1;
    if(c=='<') x -= 1;
    set.insert(std::make_pair(x, y));
    fin>>c;
    if(c=='^') ry += 1;
    if(c=='>') rx += 1;
    if(c=='v') ry -= 1;
    if(c=='<') rx -= 1;
    set.insert(std::make_pair(rx, ry));
  }
  std::cout<<set.size();
}
