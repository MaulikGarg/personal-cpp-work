#include <iostream>
#include <string>
using namespace std;

// #define DELEGATING_CONSTRUCTOR

class Ball
{
public:
#ifdef DELEGATING_CONSTRUCTOR
    Ball() : Ball("black", 10.0) {}
    Ball(string col)
        : Ball(col, 10.0)
    {
    }
    Ball(double rad)
        : Ball("black", rad)
    {
    }
    Ball(string col, double id)
        : radius{id},
          color{col}
    {
        cout << "Ball color " << color << " has radius " << radius << ".\n";
    }
#endif

#ifndef DELEGATING_CONSTRUCTOR
    Ball(double rad)
        : Ball("black", rad)
    {
    }
    Ball(string col = "black", double id = 10.0)
        : radius{id},
          color{col}
    {
        cout << "Ball color " << color << " has radius " << radius << ".\n";
    }
#endif

private:
    double radius{10.0};
    string color{"black"};
};

int main()
{
    Ball def{};
    Ball blue{"blue"};
    Ball twenty{20.0};
    Ball blueTwenty{"blue", 20.0};

    return 0;
}
