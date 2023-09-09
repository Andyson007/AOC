#include <ctype.h>
#include <iostream>
#include <fstream>
#include <vector>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::vector<int> vec;
  char c;
  int curr{};
  while (fin>>c) {
    if (isdigit(c)) {
      curr = curr*10 + c-'0';
    } else {
      vec.push_back(curr);
      curr = 0;
    }
  }
  vec.push_back(curr);
  vec[1] = 12;
  vec[2] = 2;
  int pos{};
  while (true) {
    switch (vec[pos]) {
      case 1:
        vec[vec[pos+3]] = vec[vec[pos+1]]+vec[vec[pos+2]]; break;
      case 2:
        vec[vec[pos+3]] = vec[vec[pos+1]]*vec[vec[pos+2]]; break;
      case 99:
        std::cout<<vec[0];
        return 0;
    }
    pos += 4;
  }
  return 0;
}
