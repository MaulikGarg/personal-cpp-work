// inheritance4.cpp <- filename
#include <iostream>
#include <string>
using namespace std;

class Fruit {
 private:        // make color private data member
  string color;  // all fruits have a color
 public:
  void setColor(string col) { color = col; } // sets the value of color
  string getColor() { return color; } // returns color
};

class Apple : public Fruit {
 private:
  int doctors_kept_away;  // make this private
 public:
  Apple(int doc) {  // constructor
    setColor("Red"); // since color is private we need to use a member function.
    doctors_kept_away = doc;
  }
  int getDoctor() { return doctors_kept_away; }
};

int main() {
  Apple apple(42);
  // since data members are private, we have to use member functions here
  cout << "My apple of color " << apple.getColor() << " kept away "
       << apple.getDoctor() << " doctors. ";
  return 0;
}
