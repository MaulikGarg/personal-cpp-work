// defaultConst.cpp <- file name
#include <iostream>

int threeSum(int x, const int y, int z = 0) {
  x++;  // passed value + 1
  // y++; //cannot increment y as it is constant argument
  z++;  // passed value + 1, if no value is passed, 0+1
  return x + y + z;
}

int main() {
  std::cout << threeSum(1, 2) << '\n'; //returns 5
  std::cout << threeSum(1, 2, 3) << '\n'; //returns 8
  return 0;
}
