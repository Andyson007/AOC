#include <ctype.h>
#include <fstream>
#include <iostream>
int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);

  int count{};
  int curr{};
  char c;
  bool isNegative{};
  while (fin >> c) {
    if (isdigit(c)) {
      curr = 10 * curr + c - '0';
    } else {
      if (isNegative)
        count -= curr;
      else
        count += curr;
      curr = 0;
      isNegative = (c == '-') ? true : false;
    }
  }
  std::cout << (count + curr);
  return 0;
}
