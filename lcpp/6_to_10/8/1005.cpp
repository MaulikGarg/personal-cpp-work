#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void fizzbuzz(int num)
{
    
    for (int number = 1; number <= num; number++)
    {
        bool printed{false};
        if (number % 3 == 0)
        {
            cout << "Fizz";
            printed = true;
        }
        if (number % 5 == 0)
        {
            cout << "Buzz";
            printed = true;
        }
        if (number % 7 == 0)
        {
            cout << "Pop";
            printed = true;
        }
        if (!printed){
            cout << number;
        }
        cout << '\n';
    }
}

int main()
{
    cout << "Enter a number: ";
    int number{};
    cin >> number;
    fizzbuzz(number);

    return 0;
}
