#include<iostream>

using namespace std;

int sumTo(int number){
    int sum{0};
    for (int i = 1; i <= number; i++)
    {
        sum+=i;
    }
    return sum;
    
}

int main()
{
    int number{};
    cout << "Enter a postive number: ";
    cin >> number;
    cout << "The sum from 1 to " << number << " is: " << sumTo(number);

    return 0;
}
