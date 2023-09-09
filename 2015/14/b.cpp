#include <array>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string str;
  std::map<std::string, std::array<int, 3>> deers;
  while (std::getline(fin, str)) {
    std::stringstream ss;
    ss << str;
    std::string name;
    std::string d;
    int speed;
    int endurance;
    int rest;
    ss >> name >> d >> d >> speed >> d >> d >> endurance >> d >> d >> d >> d >>
        d >> d >> rest;
    std::array<int, 3> temp;
    temp[0] = speed;
    temp[1] = endurance;
    temp[2] = rest;
    deers[name] = temp;
  }
  std::map<std::string, int> dists;
  std::map<std::string, int> points;
  for (size_t tot = 0; tot < 1001; tot++) {
    for (auto [a, b] : deers) {
      dists[a] += (tot % (b[1] + b[2])) < b[1] ? b[0] : 0;
      std::cout <<points[a]<<' '<< a << ' ' << dists[a] << '\n';
    }
    int max{-1};
    std::string name;
    for (auto [a, b] : dists) {
      if (max == -1 || b > max)
        name = a, max = b;
    }
    points[name]++;
    std::cout<<'\t'<<tot<<' '<<name<<'\n'<<'\n';
  }
  for (auto [a, b] : points) {
    std::cout<<a<<' '<<dists[a]<<' '<<b<<'\n';
  }
  return 0;
}
