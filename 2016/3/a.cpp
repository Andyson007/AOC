#include <algorithm>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int a, b, c;
  int count{};
  while (fin >> a >> b >> c) {
    if ((a+b>c)&&
        (a+c>b)&&
        (b+c>a)){
      count++;
    }
  }
  std::cout << count;
  return 0;
}
