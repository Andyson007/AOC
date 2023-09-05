#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::set<char> vowels{'a', 'e', 'i', 'o', 'u'};
  int count{};
  std::string str;
  while (fin >> str) {
    bool duplicate{false};
    int vowelCount{};
    bool substr{true};
    char prev{'\0'};
    for (char c : str) {
      if (vowels.find(c) != std::end(vowels))
        vowelCount++;
      if (prev == c)
        duplicate = true;
      if ((prev == 'a' && c == 'b') || (prev == 'c' && c == 'd') ||
          (prev == 'p' && c == 'q') || (prev == 'x' && c == 'y'))
        substr = false;
      prev = c;
    }
    if (duplicate && (vowelCount >= 3) && substr)
      count++;
  }
  std::cout << count;
  return 0;
}
