#include <iostream>
#include <string>

using namespace std;

class Fruit {
  string_view m_name{};
  string_view m_color{};

 public:
  Fruit(string_view name, string_view color) : m_name{name}, m_color{color} {}

  string_view getName() const { return m_name; }
  string_view getColor() const { return m_color; }
};

class Apple : public Fruit {
 public:
  Apple(string_view name, string_view color = "red") : Fruit{name, color} {}
};

class Banana : public Fruit {
 public:
  Banana(string_view name = "banana", string_view color = "yellow")
      : Fruit{name, color} {}
};

class GrannySmith : public Apple{
  public:
    GrannySmith(string_view name = "granny smith apple", string_view color = "green") : Apple{name,color} {}
};

int main() {
  Apple a{"red"};
  Banana b;
  GrannySmith c;

  std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
  std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
  std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

  return 0;
}
