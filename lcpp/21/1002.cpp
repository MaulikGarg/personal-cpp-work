#include <iostream>
using namespace std;

class MyString {
  string message{};

 public:
  explicit MyString(string msg) : message{msg} {}
  string_view operator()(int start, int count) {
    return string_view{this->message}.substr(start,count);
  }
};

int main() {
  MyString s{"Hello, world!"};
  std::cout << s(7, 5) << '\n';  // start at index 7 and return 5 characters

  return 0;
}
