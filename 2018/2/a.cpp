#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string str;
  int two{},three{};
  while (std::getline(fin, str)) {
    std::map<char, int> count;
    for(char c:str){
      count[c]++;
    }
    bool foundTwo{}, foundThree{};
    for(auto [a, b] : count) {
      if (b==2) {
        foundTwo = true;
      }
      if(b==3){
        foundThree = true;
      }
    }
    two += foundTwo;
    three += foundThree;
  }
  std::cout<<(two*three);
  return 0;
}
