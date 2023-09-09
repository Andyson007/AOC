#include <fstream>
#include <set>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  std::set<int> sizes;
  int temp;
  while (fin>>temp) {
    sizes.insert(temp);
  }
  return 0;
}
