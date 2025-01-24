#include "my.h"
#include <iostream>

using namespace std;

// void print_foo()
// {
//     cout << foo << '\n';
// }

// void print(int i)
// {
//     cout << i << '\n';
// }

void swap_v(int a, int b)
{
    int temp;
    temp = a; 
    a = b;
    b = temp;
    cout << a << ' ' << b << '\n';
}

void swap_r(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << a << ' ' << b << '\n';
}
