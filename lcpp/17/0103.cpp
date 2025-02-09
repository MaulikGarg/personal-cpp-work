#include<iostream>
#include<array>
using namespace std;

int main()
{
    constexpr array message {'h','e','l','l','o'};
    cout << message[1];

    return 0;
}
