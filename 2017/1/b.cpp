#include <fstream>
#include <iostream>
#include <string>
int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string str;
  std::getline(fin,str);
  int count{};
  for (size_t i = 0; i < str.size()/2; i++) {
    count += (str[i]==str[i+str.size()/2])?(str[i]-'0'):0;
  }
  std::cout<<(count*2);
  return 0;
}
