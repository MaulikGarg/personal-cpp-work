#include <functional>
#include <iostream>
using namespace std;

using ArithmeticFunction = function<int(int, int)>;

int getInt() {
  cout << "Enter an integer: ";
  int x{};
  cin >> x;
  if (!cin) {
    cin.clear();
  }
  return x;
}

char getChar() {
  char op;
  do {
    cout << "Enter a basic math operation: ";
    cin >> op;
  } while (op != '+' && op != '-' && op != '*' && op != '/');
  return op;
}

int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return x / y; }

ArithmeticFunction getArithmeticFunction(char op) {
  switch (op) {
    case '+':
      return add;
    case '-':
      return subtract;
    case '*':
      return multiply;
    case '/':
      return divide;
  }
  return nullptr;
}

int main() {
  int x{getInt()};
  char op{getChar()};
  int y{getInt()};
  if(ArithmeticFunction result {getArithmeticFunction(op)}){
    cout << x << ' ' << op << ' ' << y << " = " << result(x,y);
  }
  return 0;
}
