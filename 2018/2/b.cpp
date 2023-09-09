#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string str;
  while (std::getline(fin, str)) {
    std::string str2;
    std::ifstream fin2(argv[1]);
    while (std::getline(fin2, str2)) {
      size_t changes{};
      for (size_t i = 0; i < str.size(); i++) {
        if (str[i] != str2[i]) {
          changes++;
          if(changes == 2){
            break;
          }
        }
      }
      if (changes == 1) {
        std::string ret;
        for (size_t i = 0; i < str.size(); i++) {
          if (str[i] == str2[i]) {
            ret += str[i];
          }
        }
        std::cout<<ret;
        return 0;
      }
    }
  }
  return 0;
}
