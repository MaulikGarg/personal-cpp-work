#include<iostream>
#include<string>
#include<string_view>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;

int main()
{
    int outer{5};
    while (outer > 0)
    {
        int inner {outer};
        while (inner > 0)
        {
            cout << inner << ' ';
            inner--;
        }
        outer--;
        cout << '\n';
    }
    

    return 0;
}
