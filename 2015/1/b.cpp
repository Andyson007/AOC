#include <fstream>
#include <iostream>
int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  char c;
  int count{};
  int i{};
  while (fin >> c) {
    i++;
    count += (c=='(')?1:-1;
    if(count==-1)break;
  }
  std::cout<<i;
  return 0;
}
