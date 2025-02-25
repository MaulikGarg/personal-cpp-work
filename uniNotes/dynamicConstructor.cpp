// dynamicConstructor.cpp
#include <iostream>
using namespace std;

class Example {
  int* dynamicInt;

 public:
  Example() {
    dynamicInt = new int;  // allocate memory for int
    cout << "Allocated memory!" << '\n';
  }
  ~Example() { //destructor
    cout << "freed memory!";
    delete dynamicInt;  // free allocated memory
  }
  void setValue(int i) {
    *dynamicInt = i;
  }                                       // set value at address to given int
  int getValue() { return *dynamicInt; }  // return the value
};

int main() {
  Example object;  // calls constructor Example
  object.setValue(4);
  cout << object.getValue() << '\n';
}  // object goes out of block here, so ~Example is called
