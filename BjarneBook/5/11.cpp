#include<iostream>
#include<vector>
using namespace std;

namespace constants{
    int maxInt = 2147483647; //maximum 4 byte integer size
}
int main()
{
    int num1 {1};
    int num2 {1};
    int num3 {0};

    vector<int> fibonnaci;

    while (num3 >= 0 && num3 < constants::maxInt)
    {
        num3 = num1+num2;
        num1 = num2;
        num2 = num3;
        if(num3 > 0)
        fibonnaci.push_back(num3);
    }
    
    for(int i: fibonnaci){
        cout << i << ' ';
    }

    return 0;
}
