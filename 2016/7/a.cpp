#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string line;
  int count{};
  while (std::getline(fin, line)) {
    int layer{};
    bool inside{false};
    bool outside{false};
    for (size_t i = 0; i < 3; i++) {
      if(line[i]=='['){
        layer++;
      } else if(line[i]==']'){
        layer--;
      }
    }
    for (size_t i = 3; i < line.size(); i++) {
      switch (line[i]) {
        case '[':
          layer++;
          break;
        case ']':
          layer--;
          break;
        default:
          if((line[i]==line[i-3])&&(line[i-1]==line[i-2])&&(line[i]!=line[i-2])){
            if(layer==0){
              outside = true;
            }else{
              inside = true;
            }
          }
      }
    }
    if (outside&&!inside) {
      count++;
    }
  }
  std::cout<<count;
  return 0;
}
