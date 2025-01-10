#include<iostream>
#include<string>
#include<string_view>

using namespace std;

int main()
{

    cout << "Enter 2 numbers: ";
    int val1{}, val2{};
    cin >> val1 >> val2;

    bool greater = val1 > val2;
    greater ? cout << val1 << " is greater than " << val2 << endl 
                : cout << val2 << " is greater than " << val1 << endl;

    cout << "The sum of " << val1 << " and " << val2 << " is: " << val1 + val2 << endl;
    cout << "The difference of " << val1 << " and " << val2 << " is: " << val1 - val2 << endl;
    cout << "The product of " << val1 << " and " << val2 << " is: " << val1 * val2 << endl;
    
    cout << "The ratio of ";
    if(greater){
        cout << val1 << " to " << val2 << " is: " << static_cast<double>(val1) / val2 << ":" << val2 << endl;
    } else {
        cout << val2 << " to " << val1 << " is: " << static_cast<double>(val2) / val1 << ":" << val1 << endl;
    }

    return 0;
}
