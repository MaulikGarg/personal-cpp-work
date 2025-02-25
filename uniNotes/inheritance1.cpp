// inheritance1.cpp <- filename
#include <iostream>
#include <string>
using namespace std;

class Fruit {
 public:
  string color;  // all fruits have a color
};

class Apple : public Fruit {
 public:
  int doctors_kept_away;  // only apples keep doctors away
  Apple(int doc) {        // constructor
    color = "Red";
    doctors_kept_away = doc;
  }
};

int main() {
  Apple apple(42);
  cout << "My apple of color " << apple.color << " kept away "
       << apple.doctors_kept_away << " doctors. ";
  return 0;
}
