
#include <iostream>
#include <fstream>

int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int a,b,c,d;
  char t;
  int count{};
  while (fin>>a>>t>>b>>t>>c>>t>>d) {
    if((c>=a&&c<=b)||(a>=c&&a<=d)){
      count++;
    }
  }
  std::cout<<count;
  return 0;
}
