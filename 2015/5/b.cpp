#include <fstream>
#include <iostream>
#include <string>
int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int count{};
  std::string str;
  while (fin>>str) {
    bool flag = false;
    for (size_t i = 0; i < str.size()-1; i++) {
      char a = str[i];
      char b = str[i+1];
      for (size_t j = i+2; j < str.size()-1; j++) {
        if(a==str[j]&&b==str[j+1]){
          flag = true;
          break;
        }
      }
    }
    if(!flag)
      continue;
    flag = false;
    for (size_t i = 0; i < str.size()-2; i++) {
      if(str[i]==str[i+2])
        flag = true;
    }
    if(flag) count++;
  }
  std::cout<<count;
  return 0;
}
