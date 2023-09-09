#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int max{};
  std::string str;
  int count{};
  while (std::getline(fin,str)) {
    if(str.size()==0){
      max = std::max(count,max);
      count = 0;
    } else {
      count += std::stoi(str);
    }
  }
  std::cout<<std::max(count,max);
  return 0;
}
