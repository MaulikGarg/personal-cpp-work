//struc_class.cpp <- file name
#include <iostream>
using namespace std;

class Person {
  public:
  string name; //private by default in class
  int age;
  void display() {
    cout << "class - Name: " << name << ", Age: " << age << endl;
  }
};

struct Student {
  private:
  string name; //public by default, we can use private: in struct
  int age;

 public:
  Student(string n, int a) : name(n), age(a) {} // Constructor to initialize private members
  void display() {
    cout << "struct - Name: " << name << ", Age: " << age << endl;
  }
};

int main() {
  Person p1 = {"maulik", 84}; // class usage
  p1.display();  // Can access members directly
  Student s1("skibidi", 1); // struct usage
  s1.display();  // Can't access name/age directly (private)
}
