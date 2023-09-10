#include <algorithm>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  std::ifstream fin(argv[1]);
  int count{};
  int curr{};
  int arr[3][3];
  while (fin >> arr[curr][0] >> arr[curr][1] >> arr[curr][2]) {
    curr = (curr+1)%3;
    if (curr == 0) {
      for (size_t i = 0; i < 3; i++) {
        int max = std::max(arr[0][i], std::max(arr[1][i], arr[2][i]));
        if (arr[0][i] + arr[1][i] + arr[2][i] - max > max) {
          count++;
        }
      }
    }
  }
  std::cout << count;
  return 0;
}
