#include <fstream>
#include <iostream>
#include <queue>
int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::queue<int> window;
  int val;
  for (size_t i = 0; i < 3; i++) {
    fin>>val;
    window.push(val);
  }
  int count{};
  while (fin>>val) {
    if (val>window.front()) {
      count++;
    }
    window.pop();
    window.push(val);
  }
  std::cout<<count;
  return 0;
}
