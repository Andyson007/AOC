#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string str;
  int forward{};
  int depth{};
  int aim{};
  while (fin>>str) {
    int val;
    fin>>val;
    if(str == "forward"){
      forward += val;
      depth+=val*aim;
    } else if (str == "down") {
      aim+=val;
    } else if (str == "up") {
      aim-=val;
    }
  }
  std::cout<<(forward*depth);
  return 0;
}
