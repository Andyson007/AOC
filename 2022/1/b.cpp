#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::priority_queue<int, std::vector<int>, std::greater<int>> max;
  std::string str;
  int count{};
  int vals{};
  while (std::getline(fin, str)) {
    if (str.size() == 0) {
      max.push(count);
      count = 0;
      if (++vals > 3) {
        max.pop();
      }
    } else {
      count += std::stoi(str);
    }
  }
  max.push(count);
  max.pop();
  int tot{};
  while(!max.empty()){
    std::cout<<max.top()<<'\n';
    tot += max.top();
    max.pop();
  }
  std::cout<<tot;
  return 0;
}
