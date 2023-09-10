#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::vector<int> letters;
  char curr;
  int count{};
  int flag{0};
  int maxSize{4};
  while (fin >> curr) {
    if (count >= maxSize) {
      letters.erase(letters.begin());
    }
    int size = letters.size();
    for (size_t i = 0; i < size; i++) {
      char c = letters[size - i - 1];
      if (c == curr) {
        flag = std::max(flag, int(maxSize - i-1));
        break;
      }
    }
    if (flag == 0 && count >= maxSize) {
      std::cout << (count+1);
      return 0;
    }
    letters.push_back(curr);
    flag--;
    count++;
  }
  return 0;
}
