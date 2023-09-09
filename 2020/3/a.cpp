#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string str;
  int pos{};
  int count{};
  while (std::getline(fin, str)) {
    if(str[pos]=='#'){
      count++;
    }
    pos = (pos+3)%str.size();
  }
  std::cout<<count;
  return 0;
}
