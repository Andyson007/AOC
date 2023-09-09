#include <fstream>
#include <iostream>
int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int count{-1}, prev{}, curr;//-1 cuz the first one doesn't count
  while (fin >> curr) {
    if (prev < curr){
      count++;
    }
    prev = curr;
  }
  std::cout << count;
  return 0;
}
