#include<iostream>
using namespace std;

int main()
{
    cout << "Enter a single character: ";
    char ch{};
    cin >> ch;
    int i = ch;
    cout << "You entered '" << ch << "', which has ASCII code " << i << ".\n";
    

    return 0;
}
