#include<iostream>
#include<vector>
#include<string>
using namespace std;

using vecOfInt = vector<int>;

constexpr void fibonacci(int x,int y, vecOfInt& v, int n){
    for (int i = 0; i < n; i++)
    {
        v.push_back(x+y);
        x = y;
        y = v[i];
    }
    
}

void print(const string& stringe, const vecOfInt& vec){
    cout << stringe << '\n';
    for(int i: vec){
        cout << i << " ";
    }
}
int main()
{
    string name {"My fibbo"};
    vecOfInt series;

    constexpr int x {0};
    constexpr int y {1};
    constexpr int n {10};

    series.reserve(n); //reserves memory for n values in the vector

    fibonacci(x,y,series,n);

    print(name, series);

    return 0;
}
