#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int outer{1};
    while (outer < 6)
    {
        int inner{5};
        while (inner > 0)
        {
            if (inner > outer)
            {
                cout << "  ";
            }
            else
            {
                cout << inner << ' ';
            }
            inner--;
        }
        outer++;
        cout << '\n';
    }

    return 0;
}
