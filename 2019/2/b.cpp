#include <ctype.h>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::vector<int> vec;
  char c;
  int curr{};
  while (fin >> c) {
    if (isdigit(c)) {
      curr = curr * 10 + c - '0';
    } else {
      vec.push_back(curr);
      curr = 0;
    }
  }
  vec.push_back(curr);
  for (size_t i = 0; i < 100; i++) {
    for (size_t j = 0; j < 100; j++) {
      vec[1] = i;
      vec[2] = j;
      std::vector<int> copy(vec);
      int pos{};
      bool flag = true;
      while (flag) {
        switch (copy[pos]) {
        case 1:
          copy[copy[pos + 3]] = copy[copy[pos + 1]] + copy[copy[pos + 2]];
          break;
        case 2:
          copy[copy[pos + 3]] = copy[copy[pos + 1]] * copy[copy[pos + 2]];
          break;
        case 99:
          if (copy[0] == 19690720) {
            std::cout <<(i*100+j);
            return 0;
          }
          flag = false;
        }
        pos += 4;
      }
    }
  }
  return 0;
}
