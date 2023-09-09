#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  char posses[1000][1000]{};
  std::string line;
  while (std::getline(fin, line)) {
    int temp;
    int lDist, topDist, width, height;
    sscanf(line.c_str(), "#%d @ %d,%d: %dx%d", &temp, &lDist, &topDist, &width,
           &height);
    for (size_t i = 0; i < width; i++) {
      for (size_t j = 0; j < height; j++) {
        posses[lDist + i][topDist + j]++;
      }
    }
  }
  fin.clear();
  fin.seekg(0, fin.beg);
  while (std::getline(fin, line)) {
    int id;
    int lDist, topDist, width, height;
    sscanf(line.c_str(), "#%d @ %d,%d: %dx%d", &id, &lDist, &topDist, &width,
           &height);
    bool flag{true};
    for (size_t i = 0; i < width; i++) {
      for (size_t j = 0; j < height; j++) {
        if (posses[lDist + i][topDist + j] > 1) {
          flag = false;
        }
      }
    }
    if (flag) {
      std::cout << id;
      return 0;
    }
  }
  return 0;
}
