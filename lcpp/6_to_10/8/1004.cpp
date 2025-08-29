#include<iostream>
#include<string>
#include<string_view>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;

void fizzbuzz(int num){
    for (int number = 1; number <= num; number++)
    {
        if(number%3 == 0 && number%5 == 0) cout << "Fizzbuzz!" << '\n';
        else if(number%3 == 0) cout << "Fizz!" << '\n';
        else if(number%5 == 0) cout << "Buzz!" << '\n';
        else cout << number << '\n';
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
