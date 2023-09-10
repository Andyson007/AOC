#include <fstream>
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string str;
  int pos{};
  while (std::getline(fin, str)) {
    pos += (str[0]=='+'?[](int a){return a;}:[](int a){return -a;})(std::stoi(str.substr(1,str.size()-1)));
  }
  std::cout<<pos;
  return 0;
}
