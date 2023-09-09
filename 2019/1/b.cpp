#include <fstream>
#include <iostream>
int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int count{};
  int curr{};
  while (fin>>curr) {
    int toAdd{};
    while (curr>8) { // the largest value that becomes 0
      curr = curr/3-2;
      toAdd += curr;
    }
    count += toAdd;
  }
  std::cout<<count;
  return 0;
}
