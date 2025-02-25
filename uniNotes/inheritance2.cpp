// inheritance2.cpp <- filename
#include <iostream>
using namespace std;

class Shape {
 public:
  double area;  // all shapes have an area
};

// triangle is a shape so we inherit a shape's properties
class Triangle : public Shape {
 public:
  double angle1;  // all triangles have 3 angles
  double angle2;
  double angle3;
};

// an equilateral triangle is a triangle so we inherit a triangle
class Equilateral_Triangle : public Triangle {
 public:
  double sideLength;
  Equilateral_Triangle(double length) {
    sideLength = length;
    angle1 = angle2 = angle3 = 60.0;
    area = (1.73 / 4) * length * length;
  }
};

int main() {
  Equilateral_Triangle myTriangle(10);
  cout << "My triangle has area " << myTriangle.area;
  // even though equilateral triangle didn't inherit shape, Triangle inherited
  // it, which equilateral triangle inherited. This is called multi level
  // inheritance
  return 0;
}
