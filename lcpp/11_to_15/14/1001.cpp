#include <iostream>
#include <string>
using namespace std;

class Ball
{
private:
    string color{};
    double radius{};

public:
    Ball(string col, double rad)
        : color{col}, radius{rad}
    {
    }
    const string &getColor() const
    {
        return color;
    }
    const double &getRadius() const
    {
        return radius;
    }
};

void print(const Ball &temp)
{
    cout << "Ball(" << temp.getColor() << ", " << temp.getRadius() << ")" << '\n';
}

int main()
{
    Ball blue{"blue", 10.0};
    print(blue);

    Ball red{"red", 12.0};
    print(red);

    return 0;
}
