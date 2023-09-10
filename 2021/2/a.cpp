#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string str;
  int forward{};
  int depth{};
  while (fin>>str) {
    int val;
    fin>>val;
    if(str == "forward"){
      forward += val;
    } else if (str == "down") {
      depth+=val;
    } else if (str == "up") {
      depth-=val;
    }
  }
  std::cout<<(forward*depth);
  return 0;
}
