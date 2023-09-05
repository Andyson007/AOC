#include <fstream>
#include <iostream>
int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int count{};
  std::string str;
  while (fin>>str) {
    count+=2;
    for(int i = 0;i<str.size();i++){
      if (str[i] == '\\') {
        i++,count++;
        if(str[i]=='x') i+=2,count+=2;
      }
    }
  }
  std::cout<<count;
  return 0;
}
