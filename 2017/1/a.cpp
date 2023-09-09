#include <fstream>
#include <iostream>
int main (int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  char c;
  char prev{'\0'};
  int count{};
  char first{};
  fin>>first;
  prev = first;
  while(fin>>c){
    if(prev == c)count+=c-'0';
    prev = c;
  }
  if(first == prev) count+=prev-'0';
  std::cout <<count; 
  return 0;
}
