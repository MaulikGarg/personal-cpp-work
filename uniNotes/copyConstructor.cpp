// copyConstructor.cpp <- file name
#include <iostream>
using namespace std;

class Example {
 public:
  int value;
  Example() { value = 0; }       // default constructor
  Example(int n) { value = n; }  // parameterized constructor
  Example(Example& object) { value = object.value; cout << "Copy";}  // copy constructor
};

int main() {
  Example e1;      // default constructor called
  Example e2(2);   // parameterized constructor called
  Example e3;
  e3 = e2;  // copy constructor called

  cout << "e1: " << e1.value << '\n';  // 0
  cout << "e2: " << e2.value << '\n';  // 2
  cout << "e3: " << e3.value << '\n';  // 2
}

