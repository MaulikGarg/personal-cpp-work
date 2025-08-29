#include <iostream>
using namespace std;

constexpr int psqaures[]{0, 1, 4, 9};

bool isSquare(int n) {
  for (const auto& i : psqaures) {
    if (i == n) return true;
  }
  return false;
}
int main() {
  while (true) {
    cout << "\nEnter a single digit integer, or -1 to quit: ";
    int temp{};
    cin >> temp;

    if (temp == -1) break;

    if (isSquare(temp))
      cout << temp << " is a perfect square.";
    else
      cout << temp << " is not a perfect square.";
  }
  cout << "Bye.";
  return 0;
}
