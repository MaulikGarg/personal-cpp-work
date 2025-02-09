#include <iostream>
using namespace std;

void printstring(const char ptr[]) {
  const char* end {ptr};
  for (; *end != '\0'; end++); //get the last value
  cout << *ptr;
  while (end-- != ptr)
  {
    cout << *end;
  }
  
}

int main() {
  printstring("Hello, World!");

  return 0;
}
