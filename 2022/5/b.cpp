#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::vector<std::stack<char>> crates;
  std::string line;
  std::vector<std::string> lines;
  while (std::getline(fin, line)) {
    if (line.size() == 0) {
      break;
    }
    lines.push_back(line);
  }
  for (size_t j = 0; j < 9; j ++) {
    std::stack<char> t;
    crates.push_back(t);
  }
  for (int i = lines.size() - 2; i >= 0; i--) {
    for (int j = 0; j < lines[i].size()/4+1; j++) {
      if (lines[i][j * 4 + 1] != ' ') {
        crates[j].push(lines[i][j * 4 + 1]);
      }
    }
  }
  int amount;
  int start, end;
  std::string t;
  while (fin>>t>>amount>>t>>start>>t>>end) {
    std::stack<char> temp;
    for (size_t i = 0; i < amount; i++) {
      char top = crates[start-1].top();
      crates[start-1].pop();
      temp.push(top);
    }
    while (!temp.empty()) {
      crates[end-1].push(temp.top());
      temp.pop();
    }
  }
  for(std::stack<char> stack : crates) {
    std::cout<<stack.top();
  }
  return 0;
}
