#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Enter three int values: ";
    vector<int> ins (3);
    cin >> ins[0] >> ins[1] >> ins[2] ;
    cout << "The sum is: " << ins[0] + ins[1] + ins[2];
    cout << "\nThe product is: " << ins[0] * ins[1] * ins[2];
    return 0;
}
