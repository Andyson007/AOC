#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string line;
  int checksum{};
  while (std::getline(fin, line)) {
    std::stringstream ss;
    ss<<line;
    std::vector<int> vals;
    int val;
    while (ss>>val) {
      vals.push_back(val);
    }
    std::vector<std::vector<int>> factors;
    for(int toFactor : vals) {
      std::vector<int> facts;
      for (size_t i = 2; toFactor>1; ) {
        if (toFactor%i==0) {
          toFactor/=i;
          facts.push_back(i);
        } else {
          i++;
        }
      }
      factors.push_back(facts);
    }
    for(std::vector<int>& first : factors) {
      for(std::vector<int>& second : factors) {
        if(first.begin() == second.begin()){
          continue;
        }
        if (std::includes(first.begin(),first.end(),second.begin(),second.end())) {
          int firstTotal{1};
          for(int temp : first) {
            firstTotal *=temp;
          }
          int secondTotal{1};
          for(int temp : second) {
            secondTotal *=temp;
          }
          checksum += firstTotal/secondTotal;
        }
      }
    }
  }
  std::cout<<checksum;
  return 0;
}
