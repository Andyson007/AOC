#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string line;
  int table[3][3] = {
    {0+3, 3+1, 6+2},
    {0+1, 3+2, 6+3},
    {0+2, 3+3, 6+1}
  };
  int score{};
  while (std::getline(fin, line)) {
    score += table[line[0]-'A'][line[2]-'X'];
  }
  std::cout<<score;
  return 0;
}
