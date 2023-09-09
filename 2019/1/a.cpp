#include <fstream>
#include <iostream>
int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int count{};
  int curr{};
  while (fin>>curr) {
    count += (curr/3-2);
  }
  std::cout<<count;
  return 0;
}
