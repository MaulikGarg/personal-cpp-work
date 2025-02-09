#include<iostream>
#include<string>
#include<string_view>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;

int calculator(int num1, int num2, char operation){
    switch (operation)
    {
    case '+':
        return num1+num2;
    case '-':
        return num1-num2;
    case '*':
        return num1*num2;
    case '/':
        return num1/num2;
    default:
        cout << "Invalid!";
    }
    return 0;
}

int main()
{
    int num1{};
    int num2{};
    char operation{};

    cout << "Enter 2 ints followed by + - * or /";
    cin >> num1 >> num2 >> operation;
    cout << "Result is: " << calculator(num1, num2, operation);

    return 0;
}
