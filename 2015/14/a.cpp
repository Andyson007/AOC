#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::string str;
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
    int dist{};
    int tot{};
    while (tot < 2503) {
      for (size_t i = 0; i < endurance && tot < 2503; i++, tot++) {
        dist += speed;
      }
      for (size_t i = 0; i < rest && tot < 2503; i++, tot++){}
    }
    std::cout<<name<<": "<<dist<<'\n';
  }
  return 0;
}
