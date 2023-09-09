#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  char posses[1000][1000]{};
  std::string line;
  while (std::getline(fin, line)) {
    int temp;
    int lDist, topDist, width, height;
    sscanf(line.c_str(), "#%d @ %d,%d: %dx%d", &temp, &lDist, &topDist, &width, &height);
    for (size_t i = 0; i < width; i++) {
      for (size_t j = 0; j < height; j++) {
        posses[lDist+i][topDist+j]++;
      }
    }
  }
  int count{};
  for (size_t i = 0; i < 1000; i++) {
    for (size_t j = 0; j < 1000; j++) {
      if (posses[i][j]>1) {
        count++;
      }
    }
  }
  std::cout<<count;
  return 0;
}
