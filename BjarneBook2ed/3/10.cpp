#include <iostream>
using namespace std;

int main()
{
    cout << "Enter an operator followed by 2 numbers: ";
    char operation{};
    double num1{};
    double num2{};
    cin >> operation >> num1 >> num2;

    double result{0};
    switch (operation)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        break;
    }
    cout << "result: " << result;
    return 0;
}
