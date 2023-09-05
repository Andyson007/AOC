#include <fstream>
#include <iostream>
int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int count{};
  std::string str;
  while (fin >> str) {
    count+=2;
    for (char c : str) {
      if (c=='\\'||c=='\"') {
        count++;
    }
  }
}
std::cout << count;
return 0;
}
