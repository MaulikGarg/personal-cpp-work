#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;
class Car {
 private:
  std::string m_make;
  std::string m_model;

 public:
  Car(std::string_view make, std::string_view model)
      : m_make{make}, m_model{model} {}

  friend ostream& operator<<(ostream& os, const Car& car);
  friend bool operator<(const Car& c1, const Car& c2);
};

ostream& operator<<(ostream& os, const Car& car){
  os << '(' << car.m_make << ',' << car.m_model << ')';
  return os;
}

bool operator<(const Car& c1, const Car& c2){
  if(c1.m_make == c2.m_make){
    if(c1.m_model < c2.m_model) return true;
    return false;
  } else if(c1.m_make < c2.m_make){
    return true;
  }
  return false;
}

int main() {
  std::vector<Car> cars{{"Toyota", "Corolla"},
                        {"Honda", "Accord"},
                        {"Toyota", "Camry"},
                        {"Honda", "Civic"}};

  std::sort(cars.begin(), cars.end());  // requires an overloaded operator<

  for (const auto& car : cars)
    std::cout << car << '\n';  // requires an overloaded operator<<

  return 0;
}
