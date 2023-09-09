#include <fstream>
#include <iostream>
#include <vector>
int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::vector<int> vals;
  int val;
  while (fin>>val) {
    vals.push_back(val);
  }
  for (size_t i = 0; i < vals.size(); i++) {
    for (size_t j = i+1; j < vals.size(); j++) {
      if(vals[i]+vals[j]==2020){
        std::cout<<(vals[i]*vals[j]);
        return 0;
      }
    }
  }
  return 0;
}
