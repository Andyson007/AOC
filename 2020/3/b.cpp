#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  long long tot{1};
  int slopes[5][2] = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};
  for (auto [a, b] : slopes) {
    int pos{};
    int count{};
    std::string str;
    int y = b-1;
    int height{};
    while (std::getline(fin, str)) {
      height++;
      if (++y != b)
        continue;
      y = 0;
      if (str[pos] == '#') {
        count++;
      }
      pos = (pos + a) % str.size();
    }
    fin.clear();
    fin.seekg(0, fin.beg);
    tot *= count;
  }
  std::cout << tot;
  return 0;
}
