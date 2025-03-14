#include <iostream>
using namespace std;

class MyString {
  string message{};

 public:
  explicit MyString(string msg) : message{msg} {}

  friend ostream& operator<<(ostream& os, const MyString& obj);
  
  string operator()(int start, int count) {
    return this->message.substr(start, count);
  }
};

ostream& operator<<(ostream& os, const MyString& obj) {
  os << obj.message;
  return os;
}

int main() {
  MyString s{"Hello, world!"};
  std::cout << s(7, 5) << '\n';  // start at index 7 and return 5 characters

  return 0;
}
