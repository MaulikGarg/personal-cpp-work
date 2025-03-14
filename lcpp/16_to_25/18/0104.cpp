#include <iostream>
using namespace std;

int main() {
  int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
  constexpr int length{static_cast<int>(std::size(array))};

  for (int iteration = 0; iteration < length; iteration++) {
    bool swapMade{false};
    int endOfCurrentIteration {length - iteration};
    for (int index = 0; index < endOfCurrentIteration - 1; index++) {
      if (array[index] > array[index + 1]) {
        swap(array[index], array[index + 1]);
        swapMade = true;
      }
    }
    if (!swapMade) {
      cout << "Early termination on iteration " << iteration+1 << '\n';
      break;
    }
  }

  for (int index{0}; index < length; ++index) std::cout << array[index] << ' ';
  return 0;
}
