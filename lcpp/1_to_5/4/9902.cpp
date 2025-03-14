#include <iostream>
using namespace std;

double calculator(double firstNumber, double secondNumber, char operation);

int main()
{

    double firstNumber{};
    double secondNumber{};

    cout << "Enter the first number: ";
    cin >> firstNumber;
    cout << "Enter the second number: ";
    cin >> secondNumber;

    char operation{};
    cout << "Enter +, -, *, or /: ";
    cin >> operation;

    cout << "Result is: " << calculator(firstNumber, secondNumber, operation);

    return 0;
}

double calculator(double firstNumber, double secondNumber, char operation)
{

    if (operation == '+')
        return firstNumber + secondNumber;
    if (operation == '-')
        return firstNumber - secondNumber;
    if (operation == '*')
        return firstNumber * secondNumber;
    if (operation == '/')
        return firstNumber / secondNumber;

    return 0;
}
