#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Enter your full name: ";
    string name{};
    getline(cin >> ws, name);

    cout << "Enter your age: ";
    int age{};
    cin >> age;

    cout << "Your age + length of name is: ";
    cout << static_cast<int>(name.length()) + age;

    return 0;
}
