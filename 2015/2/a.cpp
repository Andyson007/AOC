#include <algorithm>
#include <fstream>
#include <iostream>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int a,b,c;
  char d;
  int count{};
  while (fin>>a>>d>>b>>d>>c) {
    int sideA = b*c;
    int sideB = a*c;
    int sideC = a*b;
    count += 2*(sideA+sideB+sideC) + std::min({sideC,sideB,sideA});
  }
  std::cout<<count;
  return 0;
}
