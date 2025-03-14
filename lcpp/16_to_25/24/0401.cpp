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
  double m_fiber{};

 public:
  Apple(string_view name, string_view color, double fiber)
      : Fruit{name, color}, m_fiber{fiber} {}
  double getFiber() const { return m_fiber; }
  friend ostream& operator<<(ostream& os, const Apple& obj) {
    os << "Apple(" << obj.getName() << ", " << obj.getColor() << ", "
       << obj.getFiber() << ')';
    return os;
  }
};

class Banana : public Fruit {
 public:
  Banana(string_view name, string_view color) : Fruit{name, color} {}

  friend ostream& operator<<(ostream& os, const Banana& obj) {
    os << "Banana(" << obj.getName() << ", " << obj.getColor() << ')';
    return os;
  }
};

int main() {
  const Apple a{"Red delicious", "red", 4.2};
  std::cout << a << '\n';

  const Banana b{"Cavendish", "yellow"};
  std::cout << b << '\n';

  return 0;
}
