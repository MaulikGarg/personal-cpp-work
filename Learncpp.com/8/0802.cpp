#include<iostream>
#include<string>
#include<string_view>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;

int main()
{
    char letter{'a'};
    while (letter <= 'z')
    {
        int ascii = letter;
        cout << "Letter " << letter << " has ascii code: " << ascii << '\n';
        letter++;
    }
    return 0;
}
