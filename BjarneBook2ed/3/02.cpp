#include<iostream>
#include<string>
#include<string_view>

using namespace std;

int main()
{

    cout << "Enter the number of miles: ";
    double miles{};
    cin >> miles;
    cout << "The number of kilometers is: " << miles * 1.609 << endl;

    return 0;
}
