#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Point {
 private:
  int m_x{};
  int m_y{};

 public:
  Point(int x, int y) : m_x{x}, m_y{y} {}

  friend std::ostream& operator<<(std::ostream& out, const Point& p) {
    return out << "Point(" << p.m_x << ", " << p.m_y << ')';
  }
};

class Shape {
 public:
  virtual ostream& print(ostream&) const = 0;
  friend ostream& operator<<(ostream& os, const Shape& obj) {
    return obj.print(os);
  }
  virtual ~Shape() = default;
};

class Triangle : public Shape {
  Point m_p1;
  Point m_p2;
  Point m_p3;
  ostream& print(ostream& os) const override {
    os << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
    return os;
  }

 public:
  Triangle(Point p1, Point p2, Point p3) : m_p1{p1}, m_p2{p2}, m_p3{p3} {}
};

class Circle : public Shape {
  Point m_center;
  int m_radius;
  ostream& print(ostream& os) const override {
    os << "Circle(" << m_center << ", radius " << m_radius << ")";
    return os;
  }

 public:
  Circle(Point p1, int rad) : m_center{p1}, m_radius{rad} {}
  int getRadius() const { return m_radius; }
};

int getLargestRadius(const std::vector<unique_ptr<Shape>>& v) {
  int largestRad{0};
  for (const auto& i : v) {
    if (auto* c{dynamic_cast<Circle*>(i.get())}) {
      if (c->getRadius() > largestRad) largestRad = c->getRadius();
    }
  }
  return largestRad;
}

int main() {
  std::vector<unique_ptr<Shape>> v;
  v.reserve(3);
  v.push_back(make_unique<Circle>(Point{1, 2}, 7));
  v.push_back(make_unique<Triangle>(Point{1, 2}, Point{3, 4}, Point{5, 6}));
  v.push_back(make_unique<Circle>(Point{7, 8}, 3));

  for (const auto& i : v) {
    cout << *i << '\n';
  }

  std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

  return 0;
}
