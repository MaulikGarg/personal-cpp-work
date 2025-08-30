#include <iostream>
using namespace std;

void printstring(const char ptr[]) {
  for (; *ptr != '\0'; ptr++) cout << *ptr;
}

int main() {
  printstring("Hello, World!");

  return 0;
}
