#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string line;
  int tot{};
  while (std::getline(fin, line)) {
    std::stringstream ss;
    std::string str;
    ss << line;
    int first, second;
    char c;
    char temp;
    ss >> first >> temp >> second >> c >> temp >> str;
    if((str[first-1]==c)^(str[second-1]==c)){
      tot++;
    }
  }
  std::cout<<tot;
  return 0;
}
