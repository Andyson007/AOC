#include <algorithm>
#include <fstream>
#include <iostream>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int a,b,c;
  char d;
  int count{};
  while (fin>>a>>d>>b>>d>>c) {
    count+=a*b*c+2*std::min({a+b,a+c,b+c});
  }
  std::cout<<count;
  return 0;
}
