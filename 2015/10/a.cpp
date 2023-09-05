#include <iostream>
#include <string>
int main(int argc, char *argv[]) {
  std::string curr;
  std::cin >> curr;
  for (size_t i = 0; i < 50; i++) {
    std::string next;
    int count{0};
    char prev = curr[0];
    for (char c : curr) {
      if (prev == c) {
        count++;
        continue;
      }
      next += std::to_string(count) + prev;
      count = 1;
      prev = c;
    }
    next += std::to_string(count) + prev;
    curr = next;
  }
  std::cout << curr.size();
  return 0;
}
