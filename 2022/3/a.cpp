#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string line;
  int score{};
  while (std::getline(fin, line)) {
    std::string first = line.substr(0,line.size()/2);
    std::string second = line.substr(line.size()/2);
    bool flag{true};
    for(char c : first) {
      for(char d : second) {
        if(c==d&&flag){
          if(c>='a'){
            score += c-'a'+1;
          }else{
            score += c-'A'+27;
          }
          flag = false;
        }
      }
    }
  }
  std::cout<<score;
  return 0;
}
