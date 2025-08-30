#include<iostream>
#include<string>
#include<string_view>

using namespace std;


int main()
{
    cout << "enter 3 numbers: ";
    int val1{}, val2{}, val3{};
    cin >> val1 >> val2 >> val3;

    if(val1 > val2) swap(val1,val2);
    if(val2 > val3) swap(val2, val3);
    if(val1 > val2) swap(val1,val2);
    
    cout << val1 << ' ' << val2 << ' ' << val3 << '\n';
    return 0;
}
