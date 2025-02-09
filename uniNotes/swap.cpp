// swap.cpp <- file name
#include <iostream>

//does not swap the value as only copies are modified.
int swapByVal(int value1, int value2) {
  int temp = value1;
  value1 = value2;
  value2 = value1;
  return value1;
  return value2;
  // no way to return the swapped values in call by value.
}

//address of both variables are passed, dereferences and swaps them at memory location
void swapByAddress(int* address1, int* address2){
  int temp = *address1;
  *address1 = *address2;
  *address2 = temp;
}

//references to both variables are passed, no need to dereference, can directly edit.
void swapByRef(int& ref1, int& ref2){
  int temp = ref1;
  ref1 = ref2;
  ref2 = temp;
}

int main() {
  int maulikMarks = 69;
  int broMarks = 68;
  std::cout << "Initially: " << maulikMarks << "  " << broMarks << '\n'; //bro doesnt get 69.

  swapByVal(maulikMarks, broMarks); //does not swap values.
  std::cout << "By val: " << maulikMarks << "  " << broMarks << '\n'; //bro doesnt get 69.

  swapByAddress(&maulikMarks, &broMarks); //pass addresses for both variables
  std::cout << "By Address:" << maulikMarks << "  " << broMarks << '\n'; //now bro gets 69!

  swapByRef(maulikMarks, broMarks); //pass addresses for both variables
  std::cout << "By Reference:" << maulikMarks << "  " << broMarks << '\n'; //now I get 69 again!

}
