#include <fstream>
#include <iostream>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  char c;
  int count{};
  while (fin >> c) {
    count += (c=='(')?1:-1;
  }
  std::cout<<count;
  return 0;
}
