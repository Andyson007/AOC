#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string line;
  int count{};
  while (std::getline(fin, line)) {
    std::map<char, int> map;
    int id{};
    bool flag{false};
    std::string result;
    for(char c: line){
      if(flag&&c!=']'){
        result += c;
      }else if (isalpha(c)) {
        map[c]++;
      } else if (isdigit(c)) {
        id=10*id+c-'0';
      } else if(id!=0){
        flag = true;
      }
    }
    std::vector<std::pair<char, int>> vec;
    for(auto [a,b] : map) {
      vec.push_back(std::make_pair(a, b));
    }
    std::sort(vec.begin(),vec.end(),[](std::pair<char, int> a, std::pair<char, int> b){
          return std::tie(b.second, a.first) < std::tie(a.second, b.first);
        });
    flag = true;
    for (size_t i = 0; i < 5; i++) {
      if (vec[i].first != result[i]) {
        flag = false;
      }
    }
    if(flag){
      count+=id;
    }
  }
  std::cout<<count;
  return 0;
}
