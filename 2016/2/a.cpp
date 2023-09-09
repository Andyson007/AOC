#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string str;
  int x{1},y{1};
  while(std::getline(fin, str)){
    for(char c:str){
      switch(c){
        case 'U':
          y = std::max(y-1,0); break;
        case 'D':
          y = std::min(y+1,2); break;
        case 'L':
          x = std::max(x-1,0); break;
        case 'R':
          x = std::min(x+1,2); break;
      }
    }
    std::cout<<(x+3*y+1);
  }
  return 0;
}
