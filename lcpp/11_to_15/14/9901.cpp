#include <iostream>
#include <cmath>

class Point2d
{
public:
    Point2d(){}
    Point2d(double x, double y) : m_x{x}, m_y{y}
    {
    }
    void print(){
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }
    double distanceTo(const Point2d& secPoint){
        return std::sqrt(pow(m_x - secPoint.m_x, 2) + pow(m_y - secPoint.m_y, 2));
    }

private:
    double m_x{0.0};
    double m_y{0.0};
};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}
