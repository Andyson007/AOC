#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string first, second, third;
  int score{};
  while (fin >> first >> second >> third) {
    bool flag{true};
    for (char f : first) {
      for (char s : second) {
        if (f == s && flag) {
          for (char t : third) {
            if (t == s) {
              if (t >= 'a') {
                score += t - 'a' + 1;
              } else {
                score += t - 'A' + 27;
              }
              flag = false;
              break;
            }
          }
        }
      }
    }
  }
  std::cout<<score;
  return 0;
}
