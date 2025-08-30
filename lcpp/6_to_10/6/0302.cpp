#include <iostream>
using namespace std;

constexpr bool isEven(int n)
{
    return (n%2) == 0;
}

int main()
{
    cout << "Enter a number: ";
    int n{};
    cin >> n;
    isEven(n) ? cout << "is Even" : cout << "is Odd";
    return 0;
}
