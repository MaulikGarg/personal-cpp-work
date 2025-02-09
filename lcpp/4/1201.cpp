#include<iostream>
using namespace std;

int main()
{
    cout << "Enter a single character: ";
    char ch{};
    cin >> ch;
    cout << "You entered '" << ch << "', which has ASCII code " << static_cast<int>(ch) << ".\n";
    

    return 0;
}
