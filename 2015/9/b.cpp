#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

int solve(std::map<std::pair<int, int>, int> dists, std::vector<int> opts, int curr = -1){
  if(opts.size()==0)return 0;
  int min = -1;
  for(int city : opts) {
    std::vector<int>loremIpsum(opts);
    loremIpsum.erase(std::remove(loremIpsum.begin(),loremIpsum.end(),city), loremIpsum.end());
    int dist = solve(dists, loremIpsum, city);
    if(curr !=-1) dist += dists[{city, curr}];
    if(min == -1) min = dist;
    else min = std::max(dist,min);
  }
  return min;
}

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::map<std::string, int> map;
  std::map<std::pair<int, int>, int> dists;
  int cities{};
  std::string str;
  while (std::getline(fin,str)) {
    std::stringstream ss(str);
    int dist;
    std::string city,city2;
    std::string d;
    ss>>city>>d>>city2>>d>>dist;
    if(map.find(city)==map.end()){
      map[city] = cities++;
    }
    if(map.find(city2)==map.end()){
      map[city2] = cities++;
    }
    dists[{map[city2], map[city]}] = dist;
    dists[{map[city], map[city2]}] = dist;
  }
  for(auto [a,b]:dists){
    std::cout<<a.first<<' '<<a.second<<' '<<b<<'\n';
  }
  std::vector<int> vec;
  for (size_t i = 0; i < cities; i++) {
    vec.push_back(i);
  }
  std::cout<<solve(dists, vec);
  return 0;
}
